#include <iostream>
#include <typeinfo>
using namespace std;
template<typename A = int, typename B = double,
    typename C = string>
class X {
public:
    void foo (void) const {
        cout << typeid (m_a).name () << ' '
            << typeid (m_b).name () << ' '
            << typeid (m_c).name () << endl;
    }
private:
    A m_a;
    B m_b;
    C m_c;
};
template<typename A = int, typename B = double,
    typename C = string>
void foo (void) {
    A a;
    B b;
    C c;
    cout << typeid (a).name () << ' '
        << typeid (b).name () << ' '
        << typeid (c).name () << endl;
}
/*
int multi (int x, int y = x) {
    return x * y;
}
*/
template<typename A, typename B = A>
void bar (void) {
    cout << typeid (A).name () << ' '
        << typeid (B).name () << endl;
}
template<typename A = int, typename B>
void hum (B arg) {
    cout << typeid (A).name () << ' '
        << typeid (B).name () << endl;
}
template<typename T = int>
void fun (T arg) {
    cout << typeid (T).name () << endl;
}
int main (void) {
    X<char, short, float> ().foo (); // c s f
    X<char, short> ().foo (); // c s Ss
    X<char> ().foo (); // c d Ss
    X<> ().foo (); // i d Ss
    cout << "----------------" << endl;
    foo<char, short, float> ();
    foo<char, short> ();
    foo<char> ();
    foo<> ();
    foo ();
    /*
    cout << multi (10, 13) << endl;
    cout << multi (10) << endl; */
    bar<int> ();
    hum (1.3);
    fun (2.4);
    return 0;
}
