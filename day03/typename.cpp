#include <iostream>
#include <typeinfo>
using namespace std;
class A {
public:
    typedef unsigned int uint;
    class B {};
};
template<typename T>
class C {
public:
    typedef T* pt;
};
template<typename T>
void foo (void) {
    typename T::uint u;
    typename T::B b;
    typename C<T>::pt p;
    cout << typeid (u).name () << ' '
        << typeid (b).name () << ' ' 
        << typeid (p).name () << endl;
}
int main (void) {
    A::uint u;
    A::B b;
    foo<A> ();
    return 0;
}
