// FactoryDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ToyFactory.h"

int main()
{
    std::cout << "Hello World!\n";
	//Factory design pattern
	//Example of toy factory
	int choice;
	while(1){
	std::cout << "Enter 1 for Car or 2 for Bike or 3 for Plane " << std::endl;
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "You have chosen Car" << std::endl;
	}
	else if (choice == 2) {
		std::cout << "You have chosen Bike" << std::endl;
	}
	else if (choice == 3) {
		std::cout << "You have chosen Plane" << std::endl;
	}
	else {
		std::cout << "Invalid choice" << std::endl;
		return 0;
	}
	Toy* toy = ToyFactory::createToy(choice);
	if(toy) {
		toy->showProduct();
		delete toy;
	}
	else {
		std::cout << "Toy not created" << std::endl;
	}
	}
}