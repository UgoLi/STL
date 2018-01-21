#include <iostream>
using namespace std;
template<typename IT>
void print (IT begin, IT end) {
    while (begin != end)
        cout << *begin++ << ' ';
    cout << endl;
}
