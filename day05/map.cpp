#include <iostream>
#include <map>
using namespace std;
int main (void) {
    map<string, int> msi;
    msi.insert (pair<string, int> ("张飞", 80));
    msi.insert (make_pair ("赵云", 90));
    msi["关羽"] = 70;
    msi["黄忠"] = 50;
    msi["马超"] = 60;
//  msi["马超"] = 40;
    typedef map<string, int>::iterator IT;
    pair<IT, bool> res = msi.insert (
        make_pair ("马超", 40));
    if (! res.second)
        cout << "插入失败！" << endl;
    for (IT it = msi.begin (); it != msi.end (); ++it)
        cout << it->first << ':' << it->second << endl;
    cout << "姓名:" << flush;
    string key;
    cin >> key;
    IT it = msi.find (key); // O(logN)
    if (it == msi.end ())
        cout << "查无此人！" << endl;
    else {
//      it->first = "作弊";
        it->second = 0;
        cout << it->first << ':' << it->second << endl;
    }
    /*
    cout << key << ':' << msi[key] << endl;
    */
    return 0;
}
