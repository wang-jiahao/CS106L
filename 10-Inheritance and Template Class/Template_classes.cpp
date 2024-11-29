#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//C++20特性，可以为模板增加约束条件
template<typename T>
concept r=requires(T a,T b){a+b;};

template<r T> //template classes
class container {
private:
    vector<T> arr;

public:
    void insert(const T &x) {
        arr.push_back(x);
    }

    void mySort() {
        sort(arr.begin(), arr.end());
    }

    void print() {
        for (auto i: arr) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    container<double> s;
    s.insert(3.1);
    s.insert(1.2);
    s.insert(7.3);
    s.insert(5.4);
    s.print();
    s.mySort();
    s.print();

    return 0;
}
