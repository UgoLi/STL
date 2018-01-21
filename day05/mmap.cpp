#include <iostream>
#include <map>
using namespace std;
int main (void) {
    multimap<string, int> mmi;
    mmi.insert (make_pair ("张飞", 60));
    mmi.insert (make_pair ("赵云", 70));
    mmi.insert (make_pair ("关羽", 80));
    mmi.insert (make_pair ("张飞", 65));
    mmi.insert (make_pair ("赵云", 75));
    mmi.insert (make_pair ("关羽", 85));
    typedef multimap<string, int>::iterator IT;
    for (IT it = mmi.begin (); it != mmi.end (); ++it)
        cout << it->first << ':' << it->second << endl;
    pair<IT, IT> res = mmi.equal_range ("张飞");
    int sum = 0;
    for (IT it = res.first; it != res.second; ++it)
        sum += it->second;
    cout << sum << endl;
    return 0;
}
