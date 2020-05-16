
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>

using std::out_of_range;

template<class T>
class LinkedList {
private:
    class ListNode {
    public:
        T data;
        ListNode *next;

        ListNode() : next(nullptr) {}

        explicit ListNode(const T &e, ListNode *next = nullptr) : data(e), next(next) {}

        ~ListNode() { delete next; }
    };

private:
    // 虚拟头节点
    ListNode *pHead;
    // 元素个数
    size_t m_size;

    // 将传入链表所有节点元素复制
    void _copy(const LinkedList<T> &list) {
        ListNode *p = pHead;
        ListNode *q = list.pHead->next;
        while (q) {
            p->next = new ListNode(q->data);
            p = p->next;
            q = q->next;
        }
    }

    // 获取指定位置前驱节点
    ListNode *_getPrior(const size_t &i) const {
        ListNode *p = pHead;
        for (size_t j = 0; j < i; j++)
            p = p->next;
        return p;
    }

public:

    // 默认构造器
    LinkedList() : pHead(new ListNode()), m_size(0) {}

    // 拷贝构造
    LinkedList(const LinkedList<T> &list) : m_size(list.m_size), pHead(new ListNode()){
        _copy(list);
    }

    // 将C数组转化为单链表
    LinkedList(T *arr, const size_t &n) : m_size(n), pHead(new ListNode()) {
        for (size_t i = n - 1; i >= 0; i--)
            prepend(arr[i]);
    }

    // 拷贝赋值
    LinkedList<T> &operator=(const LinkedList<T> &list) {
        if (&list == this)
            return *this;
        delete pHead;
        pHead = new ListNode();
        m_size = list.m_size;
        _copy(list);
        return *this;
    }

    // 析构函数
    ~LinkedList() { delete pHead; }

    // 在指定位置插入元素e
    void insert(const size_t &i, const T &e) {
        if (i > m_size)
            throw out_of_range("Add Failed. Illegal Index.");

        ListNode *p = _getPrior(i);
        p->next = new ListNode(e, p->next);
        m_size++;
    }

    // 在链表结尾添加元素
    void append(const T &e) { insert(m_size, e); }

    // 在链表头添加节点
    void prepend(const T &e) { insert(0, e); }

    // 获取元素个数
    size_t size() const { return m_size; }

    // 删除制定位置元素
    // 返回元素引用
    T &remove(const size_t &i) {
        if (i >= m_size)
            throw out_of_range("Remove Failed. Illegal Index.");

        ListNode *p = _getPrior(i);

        ListNode *delNode = p->next;
        T ret = delNode->data;

        p->next = delNode->next;
        delNode->next = nullptr;
        delete delNode;
        m_size--;
        return ret;
    }

    // 更新制定位置的元素
    void set(const size_t &i, const T &e) {
        if (i >= m_size)
            throw out_of_range("Set Failed. Illegal Index.");

        ListNode *p = _getPrior(i);
        p->next->data = e;
    }

    // 获取制定位置元素引用
    T &get(int i) {
        if (i < 0 || i >= m_size)
            throw out_of_range("Get Failed. Illegal Index.");

        ListNode *p = _getPrior(i);
        return p->next->data;
    }

    // 重载流插入
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T> &list) {
        os << '[';
        int i = 0;
        for (auto p = list.pHead->next; p; p = p->next) {
            os << p->data;
            if ((i++) != list.m_size - 1)
                os << '-' << '>';
        }
        return os << "NULL]";
    }
};
#endif