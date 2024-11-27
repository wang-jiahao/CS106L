#include <iostream>
#include <string>

using namespace std;

class patient {
private:
    int age;
    string name;
public:
    //构造函数
    patient(int age, string name) : age(age), name(name) {
        cout << "fill constructor" << endl;
    }

    //默认构造函数
    patient() {
        cout << "default constructor" << endl;
    }

    //拷贝构造函数
    patient(const patient &other) : age(other.age), name(other.name) {
        cout << "copy constructor" << endl;
    }

    //move constructor
    patient(patient &&other) : age(other.age), name(move(other.name)) {
        cout << "move constructor" << endl;
    }

    //析构函数
    ~patient() {
        cout << "destructor" << endl;
    }

    //=重载
    patient &operator=(const patient &other) {
        this->age = other.age;
        this->name = other.name;
        cout << "copy assignment operator" << endl;
        return *this;
    }

    //move assignment
    patient &operator=(patient &&other) {
        this->age = other.age;
        this->name = move(other.name);
        cout << "move assignment" << endl;
        return *this;
    }
};

patient readNames(const string &name);

int main() {
    patient p1 = readNames("Alley");
    patient p2;
    p2 = readNames("James");
    patient p3(patient(39,"Tom"));

    return 0;
}

patient readNames(const string &name) {
    patient p(18, name);
    return p;
}