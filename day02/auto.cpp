#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;
class A {
public:
    A (int arg = 0) : m_var (arg) {
        cout << "A构造：" << this << endl;
    }
    ~A (void) {
        cout << "A析构：" << this << endl;
    }
    void foo (void) const {
        cout << m_var << endl;
    }
    int m_var;
};
template<typename T>
class AutoPtr {
public:
    AutoPtr (T* p = NULL) : m_p (p) {}
    AutoPtr (AutoPtr& that) : m_p (that.release ()) {}
    AutoPtr& operator= (AutoPtr& rhs) {
        if (&rhs != this)
            reset (rhs.release ());
        return *this;
    }
    ~AutoPtr (void) {
        delete m_p;
    }
    T& operator* (void) const {
        return *m_p;
    }
    T* operator-> (void) const {
        return &**this;
    }
private:
    T* release (void) {
        T* p = m_p;
        m_p = NULL;
        return p;
    }
    void reset (T* p) {
        if (p != m_p) {
            delete m_p;
            m_p = p;
        }   
    }
    T* m_p;
};
template<typename T>
class AutoPtr<T[]> {
public:
    AutoPtr (T* p = NULL) : m_p (p) {}
    AutoPtr (AutoPtr& that) : m_p (that.release ()) {}
    AutoPtr& operator= (AutoPtr& rhs) {
        if (&rhs != this)
            reset (rhs.release ());
        return *this;
    }
    ~AutoPtr (void) {
        delete[] m_p;
    }
    T& operator* (void) const {
        return *m_p;
    }
    T* operator-> (void) const {
        return &**this;
    }
private:
    T* release (void) {
        T* p = m_p;
        m_p = NULL;
        return p;
    }
    void reset (T* p) {
        if (p != m_p) {
            delete[] m_p;
            m_p = p;
        }   
    }
    T* m_p;
};
void bar (void) {
//  A* pa = new A (1000);
//  auto_ptr<A> pa (new A (1000));
    AutoPtr<A> pa (new A (1000));
    pa->m_var++;
//  pa.operator->()->m_var++;
    (*pa).foo (); // 1001
//  pa.operator*().foo();
    AutoPtr<A> pb = pa;
    pb->m_var++;
    (*pb).foo (); // 1002
    AutoPtr<A> pc (new A (2000));
    pb = pc;
    pb->m_var++;
    (*pb).foo (); // 2001
    FILE* fp = fopen ("none", "r");
    if (! fp) {
        perror ("fopen");
        //delete pa;
        throw -1;
    }
    // ...
    fclose (fp);
    // ...
    //delete pa;
}
int main (void) {
    /*
    try {
        bar ();
    }
    catch (int ex) {
        cout << "错误码：" << ex << endl;
    }
    */
    AutoPtr<A[]> pa (new A[3]);
    // ...
    return 0;
}
