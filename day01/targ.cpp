#include <iostream>
using namespace std;
template<typename T>
T add (T x, T y) {
    return x + y;
}
class Integer {
public:
    Integer (int arg = 0) : m_var (arg) {}
    Integer const operator+ (Integer const& i) const {
        return m_var + i.m_var;
    }
    friend ostream& operator<< (ostream& os,
        Integer const& i) {
        return os << i.m_var;
    }
private:
    int m_var;
};
int main (void) {
    cout << add<int> (123, 456) << endl;
    cout << add<double> (1.3, 4.6) << endl;
    cout << add<string> ("Hello, ", "World!") << endl;
    /*
    cout << add<char const*> ("Hello, ",
        "World!") << endl;
    */
    cout << add<Integer> (123, 456) << endl;
    return 0;
}
