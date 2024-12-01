#include <iostream>
#include <fstream>

using namespace std;
//RAII:Resource Acquisition Is Initialization,在对象的构造函数中获得资源，并在对象的析构函数中释放资源.(自动释放，避免手动)
int main() {
    /*ifstream input;
    input.open("input.txt");//此处打开
    int n, m;
    input >> n >> m;
    cout << n << " " << m;
    input.close();//此处关闭，如果中间发生异常，则永远不会关闭，因此不符合RAII*/
    ifstream input("input.txt");//此处构造
    int n, m;
    input >> n >> m;
    cout << n << " " << m;
    //不再手动关闭，因为当input离开作用域后会自动调用析构函数，即close函数。此时如果中间发生异常，同样会调用析构函数。
    return 0;
}
