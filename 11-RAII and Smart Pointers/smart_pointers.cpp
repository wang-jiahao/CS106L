#include <iostream>
#include <memory>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int x): val(x), left(nullptr), right(nullptr) {
    }
};

int main() {
    /*node* root=new node(1);
    if (root){}
    delete root;//如果中间发生异常，则永远不会删除，不符合RAII，因此可以使用smart pointer*/
    unique_ptr<node> root = make_unique<node>(1);
    //auto n=root;false,unique_ptr不可拷贝
    //shared_ptr可以拷贝，自动计算引用次数，只有引用次数归零时删除指针指向的资源
    shared_ptr<node> n1 = make_shared<node>(3);
    cout << n1.use_count() << endl;
    auto n2 = n1;
    cout << n1.use_count() << endl;

    //不需要手动释放，smart pointer离开作用域后自动析构
    return 0;
}
