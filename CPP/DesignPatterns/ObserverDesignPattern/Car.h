#include <vector>
#include <iostream>

class Car
{
	int position = 0; // Initialize position to 0
	std::vector<class Observer*> observersList;
public:
	int getPosition() { return position; }
	void setPosition(int pos) { position = pos; notify(); }
	void attach(Observer* obs) {
		observersList.push_back(obs);
	}
	void detach(Observer* obs) {
		observersList.erase(std::remove(observersList.begin(), observersList.end(), obs), observersList.end());
	}
	void notify();
};

class Observer
{
	Car* _car;
public:
	//Constructor
	Observer(Car* car) : _car(car) {
		_car->attach(this);
	}
	virtual void update() = 0;
protected:
	Car* getCar() {
		return _car;
	}
};

class LeftObserver : public Observer
{
public:
	LeftObserver(Car* car) : Observer(car) {}
	void update() override {
		if (getCar()->getPosition() < 0) {
			std::cout << "Car is on the left side of the road" << std::endl;
		}
	}
};

class RightObserver : public Observer
{
public:
	RightObserver(Car* car) : Observer(car) {}
	void update() override {
		if (getCar()->getPosition() > 0) {
			std::cout << "Car is on the right side of the road" << std::endl;
		}
	}
};

class MiddleObserver : public Observer
{
public:
	MiddleObserver(Car* car) : Observer(car) {}
	void update() override {
		if (getCar()->getPosition() == 0) {
			std::cout << "Car is in the middle of the road" << std::endl;
		}
	}
};
