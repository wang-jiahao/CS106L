#include <iostream>
#include <thread>
#include <vector>

using namespace std;

mutex mtx;

void greet(const int &id) {
    lock_guard<mutex> lg(mtx);
    cout << "My ID is " << id << endl;
}

int main() {
    cout << "Greetings from threads!" << endl;
    /*thread thread1(greet, 1);
    thread thread2(greet, 2);
    thread1.join();
    thread2.join();*/
    vector<thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(thread(greet, i));
    }
    for (auto &threading: threads) {//thread can't be copied（thread的拷贝函数是deleted型，需要用引用）
        threading.join();
    }

    cout << "All greetings done!" << endl;


    return 0;
}
