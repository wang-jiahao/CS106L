#include <iostream>

using namespace std;

//自定义exception
class myException final: public exception {
public:
    const char *what() const noexcept override {
        return "my exception!";
    }
};

int main() {
    try {
        throw myException();
    } catch (myException &m) {
        cout << "Exception: " << m.what() << endl;
    }
    try {
        throw runtime_error("Runtime Error happened!");
    } catch (runtime_error &r) {
        cout << "Exception: " << r.what() << endl;
    }

    return 0;
}
