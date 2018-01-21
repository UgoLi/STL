#include <iostream>
using namespace std;
// 通用版本
template<typename A, typename B>
class X {
public:
    static void whoami (void) {
        cout << "X<A,B>" << endl;
    }
};
// 完全特化
template<>
class X<long, short> {
public:
    static void whoami (void) {
        cout << "X<long,short>" << endl;
    }
};
// 局部特化
template<typename A>
class X<A, short> {
public:
    static void whoami (void) {
        cout << "X<A,short>" << endl;
    }
};
template<typename C>
class X<C, C> {
public:
    static void whoami (void) {
        cout << "X<C,C>" << endl;
    }
};
template<typename A, typename B>
class X<A*, B*> {
public:
    static void whoami (void) {
        cout << "X<A*,B*>" << endl;
    }
};
int main (void) {
    X<int, char>::whoami ();
    X<int, short>::whoami ();
    X<long, short>::whoami ();
    X<long, long>::whoami ();
//  X<short, short>::whoami ();
    X<int**, char***>::whoami ();
    return 0;
}
