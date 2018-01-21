#include <iostream>
#include <cstdlib>
using namespace std;
template<typename T>
class A {
public:
    int m_var;
    void foo (void) const {
        cout << m_var << endl;
    }
    void exit (int status) {
        cout << "谢谢使用，再见！" << endl;
    }
protected:
    typedef unsigned int uint;
};
template<typename T>
class B : public A<T> {
public:
    void bar (void) {
//      A<T>::m_var = 1000;
//      A<T>::foo ();
        this->m_var = 1000;
        this->foo ();
        typename A<T>::uint u;
        A<T>::exit (0);
    }
};
int main (void) {
    B<int> b;
    b.bar ();
    return 0;
}
