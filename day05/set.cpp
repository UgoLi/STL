#include <iostream>
#include <set>
using namespace std;
int main (void) {
    set<int> si;
    si.insert (11);
    si.insert (22);
    si.insert (11);
    si.insert (33);
    si.insert (22);
    si.insert (11);
    si.insert (33);
    si.insert (33);
    for (set<int>::iterator it = si.begin ();
        it != si.end (); ++it)
        cout << *it << ' ';
    cout << endl;
    multiset<int> msi;
    msi.insert (11);
    msi.insert (22);
    msi.insert (11);
    msi.insert (33);
    msi.insert (22);
    msi.insert (11);
    msi.insert (33);
    msi.insert (33);
    for (multiset<int>::iterator it = msi.begin ();
        it != msi.end (); ++it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}
