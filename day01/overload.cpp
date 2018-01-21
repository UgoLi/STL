#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;
template<typename T>
T const& max (T const& x, T const& y) {
    cout << "<1" << typeid (x).name () << ">" << flush;
    return x < y ? y : x;
}
template<typename T>
T* const& max (T* const& x, T* const& y) {
    cout << "<2" << typeid (x).name () << ">" << flush;
    return *x < *y ? y : x;
}
char const* const& max (char const* const& x,
    char const* const& y) {
    cout << "<3" << typeid (x).name () << ">" << flush;
    return strcmp (x, y) < 0 ? y : x;
}
/*返回最大值的副本首地址(指针),为临时返回值,会导致4的返回
 * 值为临时变量的引用,那么res为这个临时变量首地址的别名
 * 临时变量不稳定(这块内存可能再次被使用存储新的值,导致
 * res的内容改变)
char const* max (char const* x, char const* y) {
    cout << "<3" << typeid (x).name () << ">" << flush;
    return strcmp (x, y) < 0 ? y : x;
}
*/
template<typename T>
T const& max (T const& x, T const& y, T const& z) {
    cout << "<4" << typeid (x).name () << ">" << flush;
    return ::max (::max (x, y), z);
}
/*
char const* const& max (char const* const& x,
    char const* const& y) {
    cout << "<3" << typeid (x).name () << ">" << flush;
    return strcmp (x, y) < 0 ? y : x;
}
*/
int main (void) {
    int a = 456, b = 123;
    cout << ::max (a, b) << endl;
    cout << *::max (&a, &b) << endl;
    char const* y = "ab";
    char const* x = "a";
    cout << ::max (x, y) << endl;
    char const* z = "abc";
    char const* const& res = ::max (x, y, z);
    cout << res << endl;
    char const* xx = "1";
    char const* yy = "12";
    char const* zz = "123";
    ::max (xx, yy, zz);
    cout << res << endl;
    //隐式推断为字符常指针类型,正常应匹配3版本
    //但<>强调使用模板函数,所以只能匹配指针模板2
    //max(char cosnt* const&,char const* cosnt&)
    cout << ::max<> (x, y) << endl;
    cout << ::max<char const> (x, y) << endl;
    //显示指定T为 char const*版本,即
    //max(char const* cosnt&,char cosnt* const&),
    //将类型变量引入类型形参T,只有版本1能得到完全匹
    //配版本.
    cout << ::max<char const*> (x, y) << endl;
    return 0;
}
