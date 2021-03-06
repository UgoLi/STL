#ifndef _MAX_H
#define _MAX_H
template<typename T>
T max (T x, T y);
template<typename T>
class Comparator {
public:
    Comparator (T x, T y);
    T max (void) const;
private:
    T m_x, m_y;
};
#include "max.cpp"
#endif // _MAX_H
