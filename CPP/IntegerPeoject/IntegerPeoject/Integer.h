#pragma once

class Integer {
	int *m_pInt;
public:
	//constructor
	Integer();
	//Parameterized constructor
	Integer(int val);
	//destructor
	~Integer();
	//Copy constrctor
	Integer(const Integer &obj);
	//Copy Operator

	//Move constructor
	Integer(Integer &&obj);
	//Move Operator

	//Getter
	int getInteger() const;
	//Setter
	void setInteger(int val);
};