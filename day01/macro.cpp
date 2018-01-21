#include <iostream>
using namespace std;
#define MAX(T) \
T max_##T (T x, T y) { \
    return x < y ? y : x; \
}
MAX (int)
/*
int max_int (int x, int y {
    return x < y ? y : x;
}
*/
MAX (double)
MAX (string)
#define max(T) max_##T
int main (void) {
    int a = 123, b = 456;
    cout << max(int) (a, b) << endl; // 456
    double c = 1.2, d = 1.3;
    cout << max(double) (c, d) << endl; // 1.3
    string e = "world", f = "hello";
    cout << max(string) (e, f) << endl; // world
    char g[] = "world", h[] = "hello";
    cout << max(string) (g, h) << endl; // world
    return 0;
}
