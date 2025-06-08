#include "Integer.h"
#include <iostream>

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int Val) :m_pInt(new int(Val))
{
	std::cout << "Integer(int val)" << std::endl;
	//m_pInt = new int(Val);
}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer::Integer(const Integer &obj)
{
	std::cout << "Integer(const Interer &obj)" << std::endl;
	//create new memory and assign object which we want to copy
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj)
{
	std::cout << "Integer(Integer &&obj)" << std::endl;
	//Assign object directly and delete old memory
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::getInteger() const
{
	std::cout << "getInteger()" << std::endl;
	return *m_pInt;
}

void Integer::setInteger(int val)
{
	std::cout << "setInteger(int Val)" << std::endl;
	*m_pInt = val;
}