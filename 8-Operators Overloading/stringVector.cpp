#include <iostream>
#include <vector>
#include <string>
//重载+=,+,<<
using namespace std;

class stringVector {
private:
    vector<string> data;
public:
    stringVector &operator+=(const string &other) {
        data.push_back(other);
        return *this;
    }

    stringVector &operator+=(const vector<string> &other) {
        for (auto s: other) {
            data.push_back(s);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const stringVector &v);
};

stringVector operator+(const stringVector &lhs, const vector<string> &rhs) {
    stringVector result = lhs; // 复制左侧对象
    result += rhs;             // 调用类的公共接口 operator+=
    return result;             // 返回结果
}

ostream &operator<<(ostream &out, const stringVector &v) {
    out << v.data[0];
    return out;
}


int main() {
    stringVector s;
    s += string("hello");
    cout << s << endl;
    return 0;
}
