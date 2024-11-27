#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct patient {
    int age;
    string name;
    string sex;

    patient(int x, string s1, string s2) : age(x), name(s1), sex(s2) {}
};

int main() {
    vector<patient> patients;
    //push_back,需要先创建patient实例，再拷贝添加到patients
    patients.push_back(patient(18, "Alley", "girl"));
    //emplace_back,可以在添加的时候创建，无需拷贝，节省空间
    patients.emplace_back(38, "James", "man");

    return 0;
}
