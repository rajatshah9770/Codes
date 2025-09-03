// AbstractFactoryDesignPatternCar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CarFactory.h"

int main()
{
    std::cout << "Hello World!\n";
	
	//create simple car
	CarFactory* simpleCarFactory = new SimpleCarFactory;

	Car* simpleCar = simpleCarFactory->createCar();

	simpleCar->showCarDetails();

	//create luxury car
	CarFactory* luxuryCarFactory = new LuxuryCarFactory;

	Car* luxuryCar = luxuryCarFactory->createCar();
	
	luxuryCar->showCarDetails();
	return 0;


}
