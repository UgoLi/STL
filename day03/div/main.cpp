#include <iostream>
using namespace std;
#include "max.h"
int main (void) {
    int a = 123, b = 456;
    double c = 1.3, d = 4.6;
    string e = "world", f = "hello";
    cout << ::max (a, b) << endl;
    cout << ::max (c, d) << endl;
    cout << ::max (e, f) << endl;
    cout << Comparator<int> (a, b).max () << endl;
    cout << Comparator<double> (c, d).max () << endl;
    cout << Comparator<string> (e, f).max () << endl;
    return 0;
}
