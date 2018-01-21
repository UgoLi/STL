#include <vector>
#include <algorithm>
#include "print.h"
bool intCmp (int a, int b) {
    return a > b;
}
class Complex {
public:
    Complex (int real = 0, int imag = 0) :
        m_real (real), m_imag (imag) {}
    friend ostream& operator<< (ostream& os,
        Complex const& c) {
        return os << c.m_real << '+' << c.m_imag
            << 'i';
    }
private:
    int m_real;
    int m_imag;
    friend bool orderByReal (Complex const&,
        Complex const&);
    friend class OrderByImag;
};
bool orderByReal (Complex const& a, Complex const& b) {
    return a.m_real < b.m_real;
}
class OrderByImag {
public:
    bool operator() (Complex const& a,
        Complex const& b) const {
        return a.m_imag < b.m_imag;
    }
};
int main (void) {
    int ai[] = {11, 31, 13, 21, 29, 17, 23, 37};
    vector<int> vi (ai, ai + 8);
    print (vi.begin (), vi.end ());
//  sort (vi.begin (), vi.end ());
//  sort (vi.rbegin (), vi.rend ());
    sort (vi.begin (), vi.end (), intCmp);
    print (vi.begin (), vi.end ());
    vector<Complex> vc;
    vc.push_back (Complex (5, 1));
    vc.push_back (Complex (4, 2));
    vc.push_back (Complex (3, 3));
    vc.push_back (Complex (2, 4));
    vc.push_back (Complex (1, 5));
    print (vc.begin (), vc.end ());
    sort (vc.begin (), vc.end (), orderByReal);
    print (vc.begin (), vc.end ());
    sort (vc.begin (), vc.end (), OrderByImag ());
    print (vc.begin (), vc.end ());
    return 0;
}
