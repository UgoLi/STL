#include <iostream>
using namespace std;
// 类模板
template<typename T>
class Comparator {
public:
    Comparator (T x, T y) : m_x (x), m_y (y) {}
    T min (void) const {
        return m_x < m_y ? m_x : m_y;
    }
    T max (void) const {
        return m_x < m_y ? m_y : m_x;
    }
private:
    T m_x;
    T m_y;
};
class Integer {
public:
    Integer (int arg = 0) : m_var (arg) {}
    bool operator< (Integer const& i) const {
        return m_var < i.m_var;
    }
    friend ostream& operator<< (ostream& os,
        Integer const& i) {
        return os << i.m_var;
    }
private:
    int m_var;
};
int main (void) {
    Comparator<int> ci (123, 456);
    cout << ci.min () << ' ' << ci.max () << endl;
    Comparator<double> cd (1.3, 4.6);
    cout << cd.min () << ' ' << cd.max () << endl;
    Comparator<string> cs ("world", "hello");
    cout << cs.min () << ' ' << cs.max () << endl;
    Comparator<Integer> cn (123, 456);
    cout << cn.min () << ' ' << cn.max () << endl;
    return 0;
}
