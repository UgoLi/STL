#include <cstring>
#include <iostream>
using namespace std;
template<typename T>
T max (T x, T y) {
    return x < y ? y : x;
}
char* max (char* x, char* y) {
    return strcmp (x, y) < 0 ? y : x;
}
template<typename T>
class Comparator {
public:
    Comparator (T x, T y) : m_x (x), m_y (y) {}
    T max (void) const {
        return m_x < m_y ? m_y : m_x;
    }
    /*
    char* max (void) const {
        return strcmp (m_x, m_y) < 0 ? m_y : m_x;
    }
    */
private:
    T m_x, m_y;
};
// 全类模板特化
/*
template<>
class Comparator<char*> {
public:
    Comparator (char* x, char* y) : m_x (x), m_y (y) {}
    char* max (void) const {
        return strcmp (m_x, m_y) < 0 ? m_y : m_x;
    }
private:
    char* m_x, *m_y;
};
*/
// 成员特化
template<>
char* Comparator<char*>::max (void) const {
    return strcmp (m_x, m_y) < 0 ? m_y : m_x;
}
int main (void) {
    int a = 123, b = 456;
    double c = 1.3, d = 4.6;
    string e = "world", f = "hello";
    char g[] = "world", h[] = "hello";
    cout << ::max (a, b) << endl;
    cout << ::max (c, d) << endl;
    cout << ::max (e, f) << endl;
    cout << ::max (g, h) << endl;
    /*
    cout << ::max<string> (g, h) << endl;
    cout << ::max (string (g), string (h)) << endl;
    */
    Comparator<int> ci (a, b);
    cout << ci.max () << endl;
    Comparator<int> cd (c, d);
    cout << cd.max () << endl;
    Comparator<string> cs (e, f);
    cout << cs.max () << endl;
    Comparator<char*> cp (g, h);
    cout << cp.max () << endl;
    return 0;
}
