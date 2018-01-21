#include <iostream>
using namespace std;
template<typename T = int, size_t S = 3>
class Array {
public:
    T& operator[] (size_t i) {
        return m_array[i];
    }
    T const& operator[] (size_t i) const {
        return const_cast<Array&> (*this) [i];
    }
    size_t size (void) const {
        return sizeof (m_array) /
            sizeof (m_array[0]);
    }
private:
    T m_array[S];
};
template<typename T, size_t S>
ostream& operator<< (ostream& os,
    Array<T, S> const& array) {
    size_t size = array.size ();
    for (size_t i = 0; i < size; ++i)
        os << '(' << array[i] << ')';
    return os;
}
int square (int x) {
    return x * x;
}
template<int x>
int square (void) {
    return x * x;
}
int main (void) {
    Array<int> a;
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    cout << a << endl;
    Array<Array<int> > b;
    for (int i = 0; i < b.size (); ++i)
        for (int j = 0; j < b[i].size (); ++j)
            b[i][j] = (i+1)*10+j+1;
//          b.operator[](i).operator[](j) = ...;
    cout << b << endl;
    for (int i = 0; i < b.size (); ++i) {
        for (int j = 0; j < b[i].size (); ++j)
            cout << b[i][j] << ' ';
        cout << endl;
    }
    Array<Array<Array<int> > > c;
    Array<Array<int, 4>, 3> d;
    for (int i = 0; i < d.size (); ++i)
        for (int j = 0; j < d[i].size (); ++j)
            d[i][j] = (i+1)*10+j+1;
    for (int i = 0; i < d.size (); ++i) {
        for (int j = 0; j < d[i].size (); ++j)
            cout << d[i][j] << ' ';
        cout << endl;
    }
    cout << square (13) << endl; // 169
    cout << square (14) << endl; // 196
    cout << square<13> () << endl; // 169
    cout << square<14> () << endl; // 196
    return 0;
}
