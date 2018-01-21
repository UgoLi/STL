#include <iostream>
using namespace std;
template<typename T>
class A {
public:
    virtual void foo (T const& arg) {
        cout << "A::foo" << endl;
    }
    virtual T bar (void) {
        cout << "A::bar" << endl;
        return T ();
    }
};
template<typename T>
class B : public A<T> {
private:
    void foo (T const& arg) {
        cout << "B::foo" << endl;
    }
};
template<typename T, typename U>
class C : public A<U> {
private:
    void foo (T const& arg) {
        cout << "C::foo" << endl;
    }
};
template<typename T, typename U>
class D : public A<U> {
private:
    T bar (void) {
        cout << "D::bar" << endl;
        return T ();
    }
};
class E {
public:
    template<typename T>
    virtual void foo (void) {}
};
int main (void) {
    B<int> b;
    A<int>& a = b;
    a.foo (0);
    C<double/*int*/, int> c;
    A<int>* pa = &c;
    pa->foo (0);
    D</*double*/int, int> d;
    pa = &d;
    pa->bar ();
    return 0;
}
