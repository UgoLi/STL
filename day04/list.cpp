#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class List {
public:
    // 构造函数、析构函数、拷贝构造和拷贝赋值
    List (void) : m_head (NULL), m_tail (NULL) {}
    ~List (void) {
        clear ();
    }
    List (List const& that) : m_head (NULL),
        m_tail (NULL) {
        for (Node* node = that.m_head; node;
            node = node->m_next)
            push_back (node->m_data);
    }
    List& operator= (List const& rhs) {
        if (&rhs != this) {
            List temp (rhs);
            swap (m_head, temp.m_head);
            swap (m_tail, temp.m_tail);
        }
        return *this;
    }
    // 获取首元素
    T& front (void) {
        if (empty ())
            throw underflow_error ("链表下溢！");
        return m_head->m_data;
    }
    T const& front (void) const {
        return const_cast<List*> (this)->front ();
    }
    // 向首部压入
    void push_front (T const& data) {
        m_head = new Node (data, NULL, m_head);
        if (m_head->m_next)
            m_head->m_next->m_prev = m_head;
        else
            m_tail = m_head;
    }
    // 从首部弹出
    void pop_front (void) {
        if (empty ())
            throw underflow_error ("链表下溢！");
        Node* next = m_head->m_next;
        delete m_head;
        m_head = next;
        if (m_head)
            m_head->m_prev = NULL;
        else
            m_tail = NULL;
    }
    // 获取尾元素
    T& back (void) {
        if (empty ())
            throw underflow_error ("链表下溢！");
        return m_tail->m_data; 
    }
    T const& back (void) const {
        return const_cast<List*> (this)->back ();
    }
    // 向尾部压入
    void push_back (T const& data) {
        m_tail = new Node (data, m_tail);
        if (m_tail->m_prev)
            m_tail->m_prev->m_next = m_tail;
        else
            m_head = m_tail;
    }
    // 从尾部弹出
    void pop_back (void) {
        if (empty ())
            throw underflow_error ("链表下溢！");
        Node* prev = m_tail->m_prev;
        delete m_tail;
        m_tail = prev;
        if (m_tail)
            m_tail->m_next = NULL;
        else
            m_head = NULL;
    }
    // 删除所有匹配元素
    void remove (T const& data) {
        for (Node* node = m_head, *next; node;
            node = next) {
            next = node->m_next;
            if (equal (node->m_data, data)) {
                if (node->m_prev)
                    node->m_prev->m_next =
                        node->m_next;
                else
                    m_head = node->m_next;
                if (node->m_next)
                    node->m_next->m_prev =
                        node->m_prev;
                else
                    m_tail = node->m_prev;
                delete node;
            }
        }
    }
    // 清空
    void clear (void) {
        while (! empty ())
            pop_back ();
    }
    // 判空
    bool empty (void) const {
        return ! m_head && ! m_tail;
    }
    // 大小
    size_t size (void) const {
        size_t nodes = 0;
        for (Node* node = m_head; node;
            node = node->m_next)
            ++nodes;
        return nodes;
    }
    // 插入输出流
    friend ostream& operator<< (ostream& os,
        List const& lst) {
        for (Node* node = lst.m_head; node;
            node = node->m_next)
            os << *node;
        return os;
    }
private:
    // 节点
    class Node {
    public:
        Node (T const& data, Node* prev = NULL,
            Node* next = NULL) : m_data (data),
            m_prev (prev), m_next (next) {}
        friend ostream& operator<< (ostream& os,
            Node const& node) {
            return os << '(' << node.m_data << ')';
        }
        T     m_data; // 数据
        Node* m_prev; // 前指针
        Node* m_next; // 后指针
    };
    bool equal (T const& a, T const& b) const {
        return a == b;
    }
    Node* m_head; // 头指针
    Node* m_tail; // 尾指针
public:
    // 正向顺序可写迭代器
    // 正向：増向头减向尾
    // 顺序：一次迭代一个
    // 可写：目标对象可被修改
    class Iterator {
    public:
        Iterator (Node* head = NULL, Node* tail = NULL,
            Node* node = NULL) : m_head (head),
            m_tail (tail), m_node (node) {}
        bool operator== (Iterator const& it) const {
            return m_node == it.m_node;
        }
        bool operator!= (Iterator const& it) const {
            return ! (*this == it);
        }
        Iterator& operator++ (void) {
            if (m_node)
                m_node = m_node->m_next;
            else
                m_node = m_head;
            return *this;
        }
        Iterator const operator++ (int) {
            Iterator old = *this;
            ++*this;
            return old;
        }
        Iterator& operator-- (void) {
            if (m_node)
                m_node = m_node->m_prev;
            else
                m_node = m_tail;
            return *this;
        }
        Iterator const operator-- (int) {
            Iterator old = *this;
            --*this;
            return old;
        }
        T& operator* (void) const {
            return m_node->m_data;
        }
        T* operator-> (void) const {
            return &**this;
        }
    private:
        Node* m_head;
        Node* m_tail;
        Node* m_node;
        friend class List;
    };
    // 起始：指向第一个元素
    Iterator begin (void) {
        return Iterator (m_head, m_tail, m_head);
    }
    // 终止：最后一个元素的下一个位置
    Iterator end (void) {
        return Iterator (m_head, m_tail);
    }
    // 插入：在loc之前插入data，返回指向新元素的迭代器
    Iterator insert (Iterator loc, T const& data) {
        if (loc == end ()) {
            push_back (data);
            return Iterator (m_head, m_tail, m_tail);
        }
        else {
            Node* node = new Node (data,
                loc.m_node->m_prev, loc.m_node);
            if (node->m_prev)
                node->m_prev->m_next = node;
            else
                m_head = node;
            node->m_next->m_prev = node;
            return Iterator (m_head, m_tail, node);
        }
    }
    // 删除：删除loc指向的元素，返回下一个位置的迭代器
    Iterator erase (Iterator loc) {
        if (loc == end ())
            throw invalid_argument ("无效参数！");
        if (loc.m_node->m_prev)
            loc.m_node->m_prev->m_next =
                loc.m_node->m_next;
        else
            m_head = loc.m_node->m_next;
        if (loc.m_node->m_next)
            loc.m_node->m_next->m_prev =
                loc.m_node->m_prev;
        else
            m_tail = loc.m_node->m_prev;
        Node* next = loc.m_node->m_next;
        delete loc.m_node;
        return Iterator (m_head, m_tail, next);
    }
};
template<>
bool List<char const*>::equal (char const* const& a,
    char const* const& b) const {
    return !strcmp (a, b);
}
// 线性查找
/*
int find (int data[], int size, int key) {
    for (int i = 0; i < size; ++i)
        if (data[i] == key)
            return i;
    return -1;
}
int* find (int* begin, int* end, int key) {
    int* it;
    for (it = begin; it != end; ++it)
        if (*it == key)
            break;
    return it;
}
*/
template<typename IT, typename KEY>
IT find (IT begin, IT end, KEY const& key) {
    IT it;
    for (it = begin; it != end; ++it)
        if (*it == key)
            break;
    return it;
}
void test1 (void) {
    List<int> li;
    li.push_front (50);
    li.push_front (40);
    li.push_front (30);
    li.push_front (20);
    li.push_front (10);
    cout << li << endl; // 10 20 30 40 50
    --li.front ();
    cout << li << endl; // 9 20 30 40 50
    li.pop_front ();
    cout << li << endl; // 20 30 40 50
    li.push_back (60);
    li.push_back (70);
    li.push_back (80);
    li.push_back (90);
    cout << li << endl; // 20 30 40 50 60 70 80 90
    li.back ()++;
    cout << li << endl; // 20 30 40 50 60 70 80 91
    li.pop_back ();
    cout << li << endl; // 20 30 40 50 60 70 80
    li.push_front (50);
    li.push_front (50);
    li.push_back (50);
    li.push_back (50);
    cout << li << endl;
    // 50 50 20 30 40 50 60 70 80 50 50
    li.remove (50);
    cout << li << endl; // 20 30 40 60 70 80
    cout << li.size () << ' ' << boolalpha
        << li.empty () << endl; // 6 false
    li.clear ();
    cout << li.size () << ' '
        << li.empty () << endl; // 0 true
}
void test2 (void) {
    List<int> l1;
    l1.push_back (100);
    l1.push_back (200);
    l1.push_back (300);
    cout << "l1: " << l1 << endl;
    List<int> l2 = l1;
    cout << "l2: " << l2 << endl;
    l1.front () += 50;
    l2.back () -= 50;
    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
    l2 = l1;
    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
    l1.back () -= 50;
    l2.front () += 50;
    cout << "l1: " << l1 << endl;
    cout << "l2: " << l2 << endl;
}
void test3 (void) {
    char sa[][256] = {
//  char const* sa[] = {
        "北京", "上海", "北京", "广州", "北京"};
    List</*string*/char const*> ls;
    for (size_t i = 0; i < sizeof (sa) /
        sizeof (sa[0]); ++i)
        ls.push_back (sa[i]);
    cout << ls << endl;
    ls.remove ("北京");
    cout << ls << endl;
}
void test4 (void) {
    List<int> li;
    for (int i = 1; i < 10; ++i)
        li.push_back (i);
    cout << li << endl;
    for (List<int>::Iterator it = li.begin ();
        it != li.end (); ++it)
        *it *= *it;
    cout << li << endl;
}
void test5 (void) {
    List<int> li;
    li.insert (li.end (), 10);
    li.insert (li.end (), 50);
    li.insert (li.end (), 90);
    cout << li << endl; // 10 50 90
    List<int>::Iterator loc = li.begin ();
    li.insert (li.insert (li.insert (
        ++loc, 40), 30), 20);
    cout << li << endl; // 10 20 30 40 50 90
    loc = li.end ();
    li.insert (li.insert (li.insert (
        --loc, 80), 70), 60);
    cout << li << endl; // 10 20 30 40 50 60 70 80 90
    loc = li.begin ();
    li.erase (li.erase (li.erase (++++++loc)));
    cout << li << endl; // 10 20 30 70 80 90
}
void test6 (void) {
    int ai[] = {11, 23, 13, 19, 17, 31, 29, 7};
    int* pi = find (ai, ai + 8, /*17*/15);
    if (pi == ai + 8)
        cout << "没找到！" << endl;
    else
        cout << "找到了：" << *pi << endl;
    List<string> ls;
    ls.push_back ("青岛");
    ls.push_back ("济南");
    ls.push_back ("威海");
    ls.push_back ("滨州");
    ls.push_back ("菏泽");
    ls.push_back ("淄博");
    ls.push_back ("临沂");
    List<string>::Iterator it = find (ls.begin (),
        ls.end (), /*"菏泽"*/"潍坊");
    if (it == ls.end ())
        cout << "没找到！" << endl;
    else
        cout << "找到了：" << *it << endl;
}
int main (void) {
//  test1 ();
//  test2 ();
//  test3 ();
//  test4 ();
//  test5 ();
    test6 ();
    return 0;
}
