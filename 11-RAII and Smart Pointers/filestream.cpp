#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    /*ifstream input("input.txt");
    string s;
    while (getline(input,s)) {
        cout << s <<endl;
    }
    input.close();*/
    /*ifstream input("input.txt");
    string s;
    input >> s;
    cout << s;*/
    /*ofstream output("input.txt");
    string s("hello, Zackaria, I am Neo");
    output<<s;*/
    freopen("input.txt", "r",stdin);
    freopen("output.txt","w",stdout);
    int n, m;
    cin >> n >> m;
    cout << n + m << endl;

    return 0;
}
