#include <vector>
#include <algorithm>
#include "print.h"
class A {
public:
    A (void) : m_var (0) {
        cout << "缺省构造：" << this << endl;
    }
    A (int arg) : m_var (arg) {
        cout << "有参构造：" << this << endl;
    }
    A (A const& a) : m_var (a.m_var) {
        cout << "拷贝构造：" << &a << "->" << this
            << endl;
    }
    A& operator= (A const& a) {
        cout << "拷贝赋值：" << &a << "->" << this
            << endl;
        m_var = a.m_var;
        return *this;
    }
    ~A (void) {
        cout << "析构函数：" << this << endl;
    }
    bool operator== (A const& a) const {
        return m_var == a.m_var;
    }
    bool operator< (A const& a) const {
        return m_var < a.m_var;
    }
    friend ostream& operator<< (ostream& os,
        A const& a) {
        return os << a.m_var;
    }
private:
    int m_var;
};
int main (void) {
    cout << "-------- 1 --------" << endl;
    vector<A> va (3);
    cout << "-------- 2 --------" << endl;
    va.push_back (A (10));
    cout << "-------- 3 --------" << endl;
    va.erase (va.begin ());
    cout << "-------- 4 --------" << endl;
    vector<A>::iterator it = find (va.begin (),
        va.end (), A(10));
    if (it != va.end ())
        cout << *it << endl;
    cout << "-------- 5 --------" << endl;
    sort (va.begin (), va.end ());
    print (va.begin (), va.end ());
    cout << "-------- X --------" << endl;
    return 0;
}
