#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
using namespace std;
class IntCmp {
public:
    bool operator() (int a, int b) const {
        return a > b;
    }
};
int main (void) {
    stack<string, vector<string> > ss;
    ss.push ("C++!");
    ss.push ("喜欢");
    ss.push ("我们");
    while (! ss.empty ()) {
        cout << ss.top ();
        ss.pop ();
    }
    cout << endl;
    queue<string, list<string> > qs;
    qs.push ("我们");
    qs.push ("喜欢");
    qs.push ("C++!");
    while (! qs.empty ()) {
        cout << qs.front ();
        qs.pop ();
    }
    cout << endl;
    priority_queue<int, vector<int>, IntCmp> pq;
    pq.push (87);
    pq.push (69);
    pq.push (11);
    pq.push (32);
    pq.push (7);
    while (! pq.empty ()) {
        cout << pq.top () << ' ';
        pq.pop ();
    }
    return 0;
}
