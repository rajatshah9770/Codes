#pragma once
#include <iostream>
#include <string>


class Toy {
private:
	std::string name;
	float price;
public:
	virtual void prepareProduct() = 0;
	virtual void assembleProduct() = 0;
	virtual void showProduct() = 0;

};

class Car : public Toy {
public:
	void prepareProduct() override {
		std::cout << "Preparing Car" << std::endl;
	}
	void assembleProduct() override {
		std::cout << "Assembling Car" << std::endl;
	}
	void showProduct() override {
		std::cout << "Car is ready" << std::endl;
	}
};

class Bike : public Toy {
public:
	void prepareProduct() override {
		std::cout << "Preparing Bike" << std::endl;
	}
	void assembleProduct() override {
		std::cout << "Assembling Bike" << std::endl;
	}
	void showProduct() override {
		std::cout << "Bike is ready" << std::endl;
	}
};
class Plane : public Toy {
public:
	void prepareProduct() override {
		std::cout << "Preparing Plane" << std::endl;
	}
	void assembleProduct() override {
		std::cout << "Assembling Plane" << std::endl;
	}
	void showProduct() override {
		std::cout << "Plane is ready" << std::endl;
	}
};

class ToyFactory
{
public:
	static Toy* createToy(int choice) {

		Toy* toy = nullptr;
		switch (choice) {
		case 1:
			toy = new Car();
			break;
		case 2:
			toy = new Bike();
			break;
		case 3:
			toy = new Plane();
			break;
		default:
			std::cout << "Invalid choice" << std::endl;
			return nullptr;
		}
		toy->assembleProduct();
		toy->prepareProduct();
		return toy;
	}
};