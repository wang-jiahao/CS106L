#include <iostream>

using namespace std;

//虚继承，避免菱形继承的问题
class A {
public:
    A() {
        cout << "A constructor" << endl;
    }

    int x = 1;
};

class B : virtual public A {
public:
    B() {
        cout << "B constructor" << endl;
    }

    int y;
};

class C : virtual public A {
public:
    C() {
        cout << "C constructor" << endl;
    }

    int z;
};

class D : public B, public C {
public:
    D() {
        cout << "D constructor" << endl;
        cout << x << endl;
    }

    int w;
};

int main() {
    D d;

    return 0;
}
