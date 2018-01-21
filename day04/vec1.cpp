#include <iostream>
#include <vector>
using namespace std;
void print (vector<int> const& vi) {
    cout << "字节数：" << sizeof (vi) << endl;
    size_t size = vi.size ();
    cout << "元素数：" << size << endl;
    cout << "容  量：" << vi.capacity () << endl;
    cout << "元素值：" << flush;
    for (size_t i = 0; i < size; ++i)
        cout << vi[i] << ' ';
    cout << endl;
}
int main (void) {
    vector<int> v1;
    print (v1);
    vector<int> v2 (3);
    print (v2);
    vector<int> v3 (3, 5);
    print (v3);
    int ai[] = {10, 20, 30, 40, 50};
    vector<int> v4 (ai, ai + 5);
    print (v4);
    vector<int> v5 (ai + 1, ai + 4);
    print (v5);
    v5.push_back (50);
    print (v5);
    v5.push_back (60);
    print (v5);
    v5.push_back (70);
    print (v5);
    v5.push_back (80);
    print (v5);
    return 0;
}
