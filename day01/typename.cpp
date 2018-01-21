#include <iostream>
using namespace std;
class A {
public:
    typedef unsigned int uint;
    class B {};
};
template<typename T>
void foo (void) {
    T::uint u;
    T::B b;
}
int main (void) {
    A::uint u;
    A::B b;
    foo<A> ();
    return 0;
}
