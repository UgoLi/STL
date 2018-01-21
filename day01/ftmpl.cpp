#include <iostream>
using namespace std;
// 函数模板
template<typename T>
T max (T x, T y) {
    return x < y ? y : x;
}
int main (void) {
    int a = 123, b = 456;
//  cout << ::max<int> (a, b) << endl; // 456
    cout << ::max (a, b) << endl;
    double c = 1.2, d = 1.3;
//  cout << ::max<double> (c, d) << endl; // 1.3
    cout << ::max (c, d) << endl;
    string e = "world", f = "hello";
//  cout << ::max<string> (e, f) << endl; // world
    cout << ::max (e, f) << endl;
    char g[] = "world", h[] = "hello";
    cout << ::max<string> (g, h) << endl; // world
//  cout << ::max (g, h) << endl;
    return 0;
}
