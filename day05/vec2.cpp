#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vi) {
    for (vector<int>::const_iterator it = vi.begin ();
        it != vi.end (); ++it)
        cout << /*++*/*it << ' ';
    cout << endl;
}
void rprint (vector<int> const& vi) {
    /*
    vector<int>::const_iterator last = vi.end (),
        before = vi.begin ();
    --last;
    --before;
    for (vector<int>::const_iterator it = last;
        it != before; --it)
        cout << *it << ' ';
    */
    for (vector<int>::const_reverse_iterator it =
        vi.rbegin (); it != vi.rend (); ++it)
        cout << *it << ' ';
    cout << endl;
}
int main (void) {
    vector<int> vi;
    for (int i = 0; i < 10; ++i)
        vi.push_back (i + 1);
    print (vi);
    rprint (vi);
    // 1 2 3 4 5 6 7 8 9 10
//  vi[4] *= 10;
    vector<int>::iterator it1 = vi.begin ();
//  *++++++++it1 *= 10;
//  cout << *it1 << endl;
    *(it1 += 4) *= 10;
    cout << *it1 << endl; // ->50
    print (vi); // 1 2 3 4 50 6 7 8 9 10
    vector<int>::iterator it2 = vi.end () - 1; // ->10
    cout << boolalpha << (it1 < it2) << endl; // true
    // it1 + 5 = it2
    cout << it1 - it2 << endl; // -5
    vector<int>::reverse_iterator it3 =
        vi.rend () - 5, it4 = vi.rbegin ();
    // it3 -> 50
    // it4 -> 10
    cout << (it3 < it4) << endl; // false
    // it3 - 5 = it4
    cout << it3 - it4 << endl; // 5
    vector<int> vn;
    vn.push_back (100);
    it1 = vn.begin ();
    cout << *it1 << endl; // 100
    vn.push_back (200);
    it1 = vn.begin ();
    cout << *it1 << endl; // 100
    return 0;
}
