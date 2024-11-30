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

class Car : virtual public Vehicle {
public:
    Car(string name): Vehicle(name) {
    }

    void drive() override {
        cout << name << " drive on road" << endl;
    }
};

class Boat : virtual public Vehicle {
public:
    Boat(string name): Vehicle(name) {
    }

    void drive() override {
        cout << name << " drive on river" << endl;
    }
};

class AmphibianCar : public Car, public Boat {
public:
    AmphibianCar(string name):Vehicle(name), Car(name), Boat(name) {
    }

    void drive() override {
        cout << name << " drive on road or river" << endl;
    }
};

int main() {
    AmphibianCar* A = new AmphibianCar("My amphibian car");
    A->drive(); // 输出Vehicle name + " drive on road or river"
    A->Car::drive(); // 调用父类同名函数
    A->Boat::drive(); // 同上
}
