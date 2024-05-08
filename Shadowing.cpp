#include <string>
#include <iostream>
using namespace std;

class Vehicle {
private:
	string regNum;
	string name;
public:
	virtual void start() {
		cout << "Key start" << endl;
	}
	virtual void stop() {
		cout << "Key stop" << endl;
	}
	virtual void drive() = 0;
};

class Car : public Vehicle {
public:
	void start() override {
		cout << "Push button start" << endl;
	}
	void stop() override {
		cout << "Push button stop" << endl;
	}
	void drive() {
		cout << "Car drive" << endl;
	}
};
class Truck: public Vehicle {
public:
	void drive() {
		cout << "Truck drive" << endl;
	}
};

class VehicleSimulator {
	Vehicle* v;
public:
	VehicleSimulator(Vehicle* vArg) : v{ vArg } {}
	void start (){
		v->start();
	}
	void stop() {
		v->stop();
	}
	void drive() {
		v->drive();
	}
};

int main() {
	Car Vehicle;
	Truck Vehicle;


	return 0;
}