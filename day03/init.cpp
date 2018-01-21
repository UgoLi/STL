#include <iostream>
using namespace std;
template<typename T>
void foo (void) {
    T var = T ();
//  int var = int ();
//  string var = string ();
    cout << '[' << var << ']' << endl;
}
template<typename T>
class A {
public:
    A (void) : m_var () {}
    void foo (void) const {
        cout << '[' << m_var << ']' << endl;
    }
private:
    T m_var;
};
int main (void) {
    foo<int> ();
    foo<string> ();
    A<int> ().foo ();
    A<string> ().foo ();
    return 0;
}
