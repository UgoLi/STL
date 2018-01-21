#include <iostream>
#include <typeinfo>
using namespace std;
template<typename A>
class X {
public:
    // 嵌套于类模板X的函数模板foo
    /*
    template<typename B>
    void foo (void) const {
        B b;
        cout << typeid (m_a).name () << ' '
            << typeid (b).name () << endl;
    } */
    template<typename B>
    void foo (void) const;
    // 嵌套于类模板X的类模板Y
    /*
    template<typename C>
    class Y {
    public:
        void hum (void) const {
            cout << typeid (m_c).name () << endl;
        }
    private:
        C m_c;
    };
    */
    template<typename C> class Y;
private:
    A m_a;
};
template<typename A>
    template<typename B>
void X<A>::foo (void) const {
    B b;
    cout << typeid (m_a).name () << ' '
        << typeid (b).name () << endl;
}
template<typename A>
    template<typename C>
class X<A>::Y {
public:
    void hum (void) const {
        cout << typeid (m_c).name () << endl;
    }
private:
    C m_c;
};
template<typename A, typename B, typename C>
void bar (A a, B b, C c) {
    X<A> x, *px = &x;
    x.template foo<B> ();
    px->template foo<B> ();
    typename X<A>::template Y<C> y;
    y.hum ();
}
int main (void) {
    X<int> x;
    x.foo<double> ();
    bar (1, 1.0, "1");
    return 0;
}
