#include <iostream>
using namespace std;
#define max(x, y) ((x) < (y) ? (y) : (x))
int main (void) {
    int a = 123, b = 456;
    cout << max (a, b) << endl; // 456
    double c = 1.2, d = 1.3;
    cout << max (c, d) << endl; // 1.3
    string e = "world", f = "hello";
    cout << max (e, f) << endl; // world
    char g[] = "world", h[] = "hello";
    cout << max (g, h) << endl; // ?
    return 0;
}
