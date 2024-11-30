#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string name;

public:
    Vehicle(string name): name(name) {
    };

    virtual void drive() = 0;
};

class Car :public Vehicle {
public:
    Car(string name): Vehicle(name) {
    }

    void drive() override {
        driveAsCar();
    }

    virtual void driveAsCar(){
        cout << name << " drive on road" << endl;
    }
};

class Boat :public Vehicle {
public:
    Boat(string name): Vehicle(name) {
    }

    void drive() override {
        driveAsBoat();
    }

    virtual void driveAsBoat() {
        cout << name << " drive on river" << endl;
    }
};

class AmphibianCar : public Car, public Boat {
public:
    AmphibianCar(string name):Car(name), Boat(name) {
    }

    void driveAsCar() override{
        cout << Car::name << " drive on road as car" << endl;
    }

    void driveAsBoat() override{
        cout << Boat::name << " drive on river as boat" << endl;
    }
};

int main() {
    AmphibianCar* A = new AmphibianCar("My amphibian car");
    Car* CarMode = A;
    Boat* BoatMode = A;
    CarMode->drive(); // 将Car中的drive()方法重写为driveAsCar()
    BoatMode->drive(); // 将Boat中的drive()方法重写为driveAsBoat()
}
