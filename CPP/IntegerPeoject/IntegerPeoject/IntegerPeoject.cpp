// IntegerPeoject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Integer.h"

Integer Add(const Integer &obj1, const Integer &obj2)
{
	Integer temp;
	temp.setInteger(obj1.getInteger() + obj2.getInteger());
	return temp;
}

int main()
{
	Integer x(1), y(3);
	std::cout << "Hello World!\n";
	Integer a{ 5 };
	Integer b;
	b.setInteger(50);
	std::cout << "Copy initiated: " << std::endl;
	Integer c{ a };//Copy constructor will get called because a is r value and move constructor works on l value
	Integer k{ std::move(a) };//Forcefull call of move constructor
	//Integer b{static_cast<Integer &&>(a)};//static_cast<Integer &&> is replaced with std move.
	std::cout << "Value inside pointer: " << b.getInteger() << std::endl;
	x.setInteger(Add(x, y).getInteger());//If both copy and move is written then move will get called.
	std::cout << "Value of addition on Obj: " << x.getInteger() << std::endl;
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
