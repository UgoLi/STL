#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
void foo (T x, T y) {
    cout << typeid (x).name () << ' '
        << typeid (y).name () << endl;
}
template<typename T>
void bar (T const& x, T const& y) {
    cout << typeid (x).name () << ' '
        << typeid (y).name () << endl;
}
template<typename R, typename T>
R hum (T x) {
    R y;
    cout << typeid (x).name () << ' '
        << typeid (y).name () << endl;
    return y;
}
int main (void) {
    int a, b;
    foo (a, b); // i i 
    double c, d;
    bar (c, d); // d d
    char e[256], f[256];
    foo (e, f); // Pc Pc
    bar (e, f); // A256_c A256_c
    e[0] = 'B'; // *(e+0) = 'B'
    cout << 0[e] << endl; // cout << *(0+e) << endl;
    cout << sizeof (e) << endl; // 256
    char (*g)[256] = &e;
    foo ("hello", "tarena"); // PKc PKc
//  bar ("hello", "tarena"); // A6_c A7_c
    bar (string ("hello"), string ("tarena"));
//  foo (a, c);
    // 隐式类型转换不能和隐式推断同时使用
    foo ((double)a, c); // d d
    foo<int> (a, c); // i i
    double i = hum<double> (10); // i d
    return 0;
}
