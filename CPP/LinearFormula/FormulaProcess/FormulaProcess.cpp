// FormulaProcess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FormulaProcess.h"
#include <list>

int main()
{
    std::cout << "Hello World!\n";

	double numerator = 5.0;
	double offset = 2.0;
	double denominator = 8.6;

	//make formula (numerator*x^1 + offset^0) / denominator*x^0
	/*
												/
								+									*
				numerator*x^1		offset^0			denominator		x^0
					*					^								 ^
		neumerator		x^1		offset		0						x			0
						 ^
					x			1
	*/

	FormulaProcess* formula = new Division (
		new Addition(
			new Multiplication(new Number(std::to_string(numerator)),new Power(new Variable("x"), 1)),new Power(new Number(std::to_string(offset)), 0)),
		new Multiplication(
			new Number(std::to_string(denominator)),new Power(new Variable("x"), 0)
		)
	);

	//print formula
	std::cout << "Original formula: " << formula->toString() << std::endl;

	//if formula is with n no of power
    list<string> numeratorList{ "200", "300", "400", "500" };
	list<string> denominatorList{ "2", "3", "4", "5" };
	
	//make formula (numeratorList[0]*x^3 + numeratorList[1]*x^2 + numeratorList[2]*x^1 + numeratorList[3]*x^0 ) / (denominatorList[0]*x^3 + denominatorList[1]*x^2 + denominatorList[2]*x^1 + denominatorList[3]*x^0 ) - for n number of powers genric without hardcoded powers
	FormulaProcess* formulaN = new Division(
		new Addition(
			new Addition(
				new Addition(
					new Multiplication(new Number(numeratorList.front()), new Power(new Variable("x"), 3)),
					new Multiplication(new Number(*(++numeratorList.begin())), new Power(new Variable("x"), 2))
				),
				new Multiplication(new Number(*(++(++numeratorList.begin()))), new Power(new Variable("x"), 1))
			),
			new Multiplication(new Number(numeratorList.back()), new Power(new Number("1"), 0))
		),
		new Addition(
			new Addition(
				new Addition(
					new Multiplication(new Number(denominatorList.front()), new Power(new Variable("x"), 3)),
					new Multiplication(new Number(*(++denominatorList.begin())), new Power(new Variable("x"), 2))
				),
				new Multiplication(new Number(*(++(++denominatorList.begin()))), new Power(new Variable("x"), 1))
			),
			new Multiplication(new Number(denominatorList.back()), new Power(new Number("1"), 0))
		)
	);
	//print formulaN
	std::cout << "Original formula with n powers: " << formulaN->toString() << std::endl;
	//Things are yet to be handled
	// 
	//issue with brackets
	//issue with +-
	//issue with multiply by 1
	//Call function for n number of powers without hardcoding powersS
	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
