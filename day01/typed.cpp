#include <iostream>
using namespace std;
int max_int (int x, int y) {
    return x < y ? y : x;
}
double max_double (double x, double y) {
    return x < y ? y : x;
}
string max_string (string x, string y) {
    return x < y ? y : x;
}
int main (void) {
    int a = 123, b = 456;
    cout << max_int (a, b) << endl; // 456
    double c = 1.2, d = 1.3;
    cout << max_double (c, d) << endl; // 1.3
    string e = "world", f = "hello";
    cout << max_string (e, f) << endl; // world
    char g[] = "world", h[] = "hello";
    cout << max_string (g, h) << endl; // world
    return 0;
}
