// ObserverDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"

void Car::notify() {
	for (Observer* obs : observersList) {
		obs->update();
	}
}

int main()
{
    Car* car = new Car();
    
	LeftObserver* leftObs = new LeftObserver(car);
	RightObserver* rightObs = new RightObserver(car);
	MiddleObserver* middleObs = new MiddleObserver(car);	

	std::cout << "Press left, right, middle or exit" << std::endl;

	char input;
	bool breakLoop = false;

	while(breakLoop == false) {
		std::cin >> input;
		switch (input) {
		case 'l':
			car->setPosition(-1);
			break;
		case 'r':
			car->setPosition(1);
			break;
		case 'm':
			car->setPosition(0);
			break;
		case 'e':
			breakLoop = true;
			break;
		default:
			std::cout << "Invalid input. Please press left, right, middle or exit" << std::endl;
			break;
		}
	}
}

//With observers attached to the car, when the car's position is changed, the observers are notified and they print messages based on the car's position.
//disadvantage: Memory management is manual, which can lead to memory leaks if not handled properly. In a production environment, consider using smart pointers for better memory management.
//advantage: The observer pattern is implemented, allowing for dynamic response to changes in the car's position.
//flow: setPosition -> notify -> update (in each observer) -> Do action defined in update func of child class if condition matches. 