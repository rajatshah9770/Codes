#pragma once
#include <string>

using namespace std;

enum precedence {
	prec_NONE = 0,
    prec_ADD = 1,
	prec_SUB = 1,
	prec_MUL = 2,
	prec_DIV = 2,
	prec_POW = 3,
	prec_NUM = 4
};

// (number*variable^power)+(number*variable^power)+(number*variable^power)/(number*variable^power)+(number*variable^power)+(number*variable^power)
// with tree aproach
//Abstract class for processing formulas
class FormulaProcess {
public:
	virtual std::string toString() const = 0; // virtual keyword enables polymorphism which allows derived classes to override this method
	virtual FormulaProcess* simplify() = 0; // =0 makes this pure virtual, meaning derived classes must implement it
	virtual ~FormulaProcess() = default; // virtual destructor to ensure proper cleanup of derived classes

	virtual int getPrecedence() const = 0; // whenever getter is there we can make function const if not changing any member variables
	//Use of precedance For example, in the expression 2 + 3 * 4, multiplication has higher precedence than addition, so 3 * 4 is evaluated before adding 2.
};

//Operand can be number, variable or power
class Operand : public FormulaProcess {
	//empty for now
};

class Number : public Operand {
    string numValue;
public:
    //constructor
    Number(const string& value):numValue(value) {}

    // In Number::toString(), make a mutable copy of numValue before modifying it
    string toString() const override {
		//remove trailing .0 for integers
		string result = numValue; // make a mutable copy
		if (result.find('.') != string::npos) {//npos returns npos if not found
			// Remove trailing zeros
			result.erase(result.find_last_not_of('0') + 1, string::npos);
			// If the last character is a '.', remove it as well
			if (!result.empty() && result.back() == '.') {
				result.pop_back();
			}
		}
		return result;
    }
    FormulaProcess* simplify() override {
        return new Number(numValue); // return a new instance of Number with the same value
    }
	int getPrecedence() const override {
		return prec_NUM; // Highest precedence for numbers
	}
};

class Variable : public Operand {
	string VarValue;
public:
	//constructor
	Variable(const string& value) : VarValue(value) {}

	//Override functions
	string toString() const override {
		return VarValue;
	}
	FormulaProcess* simplify() override {
		return new Variable(VarValue); // return a new instance of Variable with the same value
	}
	int getPrecedence() const override {
		return prec_NUM; // Highest precedence for variables
	}
};

class Power : public Operand {
	FormulaProcess* base; // base can be a number or variable eg  x^2 or 2^3 here base is x, it is formula process pointer to allow both number and variable
	int exponent; // actual exponent is power of 10
public:
	//constructor
	Power(FormulaProcess* baseVal, int power) : base(baseVal), exponent(power) {}

	//Destructor to clean up base
	~Power() {delete base;}
	//Override functions
	string toString() const override {
		if (exponent == 0) return "1";
		if (exponent == 1) return base->toString();
		return base->toString() + "^" + std::to_string(exponent);
	}
	FormulaProcess* simplify() override {
		// Simplification logic for power can be added here
		if (exponent == 0) { delete base; return new Number("1"); }
		if (exponent == 1) return base->simplify();
		return new Power(base->simplify(), exponent); // return a new instance of Power with simplified base
	}
	int getPrecedence() const override {
		return prec_POW; // Highest precedence for power
	}
};


//Operator can be addition, subtraction, multiplication or division
class Operator : public FormulaProcess {
protected:
	FormulaProcess* left; // left operand
	FormulaProcess* right; // right operand
public:
	//constructor
	Operator(FormulaProcess* leftVal, FormulaProcess* rightVal) : left(leftVal), right(rightVal) {}
	//Destructor to clean up left and right
	virtual ~Operator() { delete left; delete right; } // virtual to ensure derived class destructors are called
};

class Addition : public Operator {
public:
	//constructor
	//Addition(FormulaProcess* leftVal, FormulaProcess* rightVal) : Operator(leftVal, rightVal) {}
	using Operator::Operator; // inherit constructor from base class
	
	//Override functions
	string toString() const override {
		return "(" + left->toString() + " + " + right->toString() + ")";
	}
	FormulaProcess* simplify() override {
		// Simplification logic for addition can be added here
		return new Addition(left->simplify(), right->simplify()); // return a new instance of Addition with simplified operands
	}
	int getPrecedence() const override {
		return prec_ADD; // Precedence for addition
	}
};

class Subtraction: public Operator {
	public:
	//constructor
	//Subtraction(FormulaProcess* leftVal, FormulaProcess* rightVal) : Operator(leftVal, rightVal) {}
	using Operator::Operator; // inherit constructor from base class
	//Override functions
	string toString() const override {
		return "(" + left->toString() + " - " + right->toString() + ")";
	}
	FormulaProcess* simplify() override {
		// Simplification logic for subtraction can be added here
		return new Subtraction(left->simplify(), right->simplify()); // return a new instance of Subtraction with simplified operands
	}
	int getPrecedence() const override {
		return prec_SUB; // Precedence for subtraction
	}
};

class Multiplication : public Operator {
	public:
	//constructor
	//Multiplication(FormulaProcess* leftVal, FormulaProcess* rightVal) : Operator(leftVal, rightVal) {}
	using Operator::Operator; // inherit constructor from base class
	//Override functions
	string toString() const override {
		return "(" + left->toString() + " * " + right->toString() + ")";
	}
	FormulaProcess* simplify() override {
		// Simplification logic for multiplication can be added here
		return new Multiplication(left->simplify(), right->simplify()); // return a new instance of Multiplication with simplified operands
	}
	int getPrecedence() const override {
		return prec_MUL; // Precedence for multiplication
	}

};

class Division : public Operator {
	public:
	//constructor
	//Division(FormulaProcess* leftVal, FormulaProcess* rightVal) : Operator(leftVal, rightVal) {}
	using Operator::Operator; // inherit constructor from base class
	//Override functions
	string toString() const override {
		return "(" + left->toString() + " / " + right->toString() + ")";
	}
	FormulaProcess* simplify() override {
		// Simplification logic for division can be added here
		return new Division(left->simplify(), right->simplify()); // return a new instance of Division with simplified operands
	}
	int getPrecedence() const override {
		return prec_DIV; // Precedence for division
	}
};