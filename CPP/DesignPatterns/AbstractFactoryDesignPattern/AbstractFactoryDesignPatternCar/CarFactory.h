#pragma once
#include <string>
#include <iostream>


//abstract Tire class - has a relationship with Car
class Tire
{
	std::string tireType;
	int tireSize;
public:
	//constructor
	Tire(std::string type, int size) : tireType(type), tireSize(size) {}
	std::string getTireType() { return tireType; }
	int getTireSize() { return tireSize; }
};
class simpleTire : public Tire
{
public:
	simpleTire(std::string type, int size) : Tire("SimpleTire", 50) {}
};
class luxuryTire : public Tire
{
public:
	luxuryTire(std::string type, int size) : Tire("LuxuryTire", 100) {}
};

//abstract body class - has a relationship with Car
class body
{
private:
	std::string bodyType;
	int bodySize;
public:
	//constructor
	body(std::string type, int size) : bodyType(type), bodySize(size) {}
	std::string getBodyType() { return bodyType; }
	int getBodySize() { return bodySize; }
};
class simpleBody : public body
{
public:
	simpleBody(std::string type, int size) : body("SimpleBody", 50) {}
};
class luxuryBody : public body
{
public:
	luxuryBody(std::string type, int size) : body("LuxuryBody", 100) {}
};

//Car base class
class Car
{
private:
	std::string carName;
	Tire* tire;
	body* carBody;
public:
	//constructor
	Car(std::string name, Tire* t, body* b) : carName(name), tire(t), carBody(b) {}
	Car(std::string name) : carName(name) {}

	void setTire(Tire* t) { tire = t; }
	void setBody(body* b) { carBody = b; }
	void showCarDetails() {
		std::cout << "Car Name: " << carName << std::endl;
		std::cout << "Tire Type: " << tire->getTireType() << ", Tire Size: " << tire->getTireSize() << std::endl;
		std::cout << "Body Type: " << carBody->getBodyType() << ", Body Size: " << carBody->getBodySize() << std::endl;
	}
};



//CarFactory abstract base class
class CarFactory
{
	Car* car;
public:
	virtual Tire* createTire() = 0;
	virtual body* createBody() = 0;
	virtual Car* createCar() = 0;
};

//Concrete CarFactory classes
class SimpleCarFactory : public CarFactory
{
	public:
		Tire* createTire() override {
			return new simpleTire("SimpleTire", 50);
		}
		body* createBody() override {
			return new simpleBody("SimpleBody", 50);
		}
		Car* createCar() override {
			Car* car = new Car("SimpleCar");
			car->setTire(createTire());
			car->setBody(createBody());
			return car;
		}
};
class LuxuryCarFactory : public CarFactory
{
	public:
		Tire* createTire() override {
			return new luxuryTire("LuxuryTire", 100);
		}
		body* createBody() override {
			return new luxuryBody("LuxuryBody", 100);
		}
		Car* createCar() override {
			Car* car = new Car("LuxuryCar");
			car->setTire(createTire());
			car->setBody(createBody());
			return car;
		}
};


