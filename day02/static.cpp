#include <iostream>
using namespace std;
template<typename T>
class A {
public:
    void print (void) const {
        cout << "&s_var: " << &s_var << ", "
            << "&m_var: " << &m_var << endl;
    }
private:
    static int s_var;
    int m_var;
};
template<typename T>
int A<T>::s_var;
int main (void) {
    A<int> a1, a2;
    A<double> a3, a4;
    a1.print ();
    a2.print ();
    a3.print ();
    a4.print ();
    return 0;
}
