#include <list>
//#include <algorithm>
#include "print.h"
bool intCmp (int a, int b) { return a > b; }
int main (void) {
    int ai[] = {1, 1, 2, 2, 1, 2, 3, 2, 2, 1, 1};
    list<int> li (ai, ai + 11);
    print (li.begin (), li.end ());
    //sort (li.begin (), li.end ());
    li.sort (intCmp);
    print (li.begin (), li.end ()); // 3 2 1
    li.unique ();
    print (li.begin (), li.end ());
    list<int>::iterator pos = li.begin ();
    ++pos; // -> 2
    list<int> lj;
    lj.push_back (1000);
    lj.push_back (2000);
    lj.push_back (3000);
    lj.push_back (4000);
    lj.push_back (5000);
    /*
    li.splice (pos, lj);
    *//*
    list<int>::iterator del = lj.begin ();
    li.splice (pos, lj, ++++del);
    */
    list<int>::iterator begin = lj.begin (),
        end = lj.end ();
    li.splice (pos, lj, ++begin, --end);
    cout << "lj: ";
    print (lj.begin (), lj.end ());
    cout << "li: ";
    print (li.begin (), li.end ());
    list<int> l1;
    l1.push_back (10);
    l1.push_back (20);
    l1.push_back (30);
    l1.push_back (40);
    l1.push_back (50);
    l1.sort (intCmp);
    list<int> l2;
    l2.push_back (5);
    l2.push_back (25);
    l2.push_back (45);
    l2.sort (intCmp);
    l1.merge (l2, intCmp);
    cout << "l1:";
    print (l1.begin (), l1.end ());
    cout << "l2:";
    print (l2.begin (), l2.end ());
    return 0;
}
