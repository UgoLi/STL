#include <iostream>
using namespace std;
int square (int x) {
    return x * x;
}
template<int x>
int square (void) {
    return x * x;
}
/*
template<float x>
float squaref (void) {
    return x * x;
}
*/
template<char const* str>
void print (void) {
    cout << str << endl;
}
char g_str[] = "Hello, World !";
char g_buf[1024];
int main (void) {
    cout << square (13) << endl;
    cout << square<10+3> () << endl;
    int a = 13;
    cout << square (a) << endl;
    int const /*volatile */b = 13;
    cout << square<b> () << endl;
//  cout << squaref<1.3> () << endl;
    print<g_str> ();
    cin >> g_buf;
    print<g_buf> ();
    return 0;
}
