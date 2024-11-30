#include <iostream>

using namespace std;

class animal {
public:
    virtual void sound() {
        cout << "animal sound" << endl;
    }

    virtual ~animal() = default;
};

class dog : public animal {
public:
    void sound() override {
        cout << "bark" << endl;
    }

    ~dog() override = default;
};

class cat : public animal {
public:
    void sound() override {
        cout << "meow" << endl;
    }

    ~cat() override = default;
};

int main() {
    animal* a1=new dog();
    animal* a2=new cat();
    a1->sound();
    a2->sound();
    delete a1;
    delete a2;

    return 0;
}
