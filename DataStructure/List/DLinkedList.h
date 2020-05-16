
#ifndef _DLINKEDLIST_
#define _DLINKEDLIST_

#include <iostream>
#include "LinkedList.h"

using std::ostream;
using std::out_of_range;

template<class T>
class DLinkedList {
private:
    class DListNode {
    public:
        T data;
        DListNode *next, *prior;

        DListNode() : prior(nullptr), next(nullptr) {}

        explicit DListNode(T e, DListNode *p = nullptr, DListNode *n = nullptr) : data(e), prior(p), next(n) {}

        ~DListNode() { delete next; }
    };

private:
    // 虚拟头节点
    DListNode *pHead;
    // 元素个数
    size_t m_size;

    // 在p节点后添加元素
    void _add(DListNode *p, const T &e) {
        auto *node = new DListNode(e, p, p->next);
        p->next->prior = node;
        p->next = node;
        m_size++;
    }

    // 删除p节点后继
    // 返回元素的引用
    T &_remove(DListNode *p) {
        T ret = p->data;
        p->prior->next = p->next;
        p->next->prior = p->prior;
        p->next = p->prior = nullptr;
        delete p;
        m_size--;
        return ret;
    }

    // 将传入链表节点所有元素复制
    void _copy(const DLinkedList<T> &list) {
        pHead = new DListNode();
        pHead->next = pHead->prior = pHead;
        DListNode *p = list.pHead->next;
        while (p != list.pHead) {
            append(p->data);
            p = p->next;
        }
    }

    // 获取指定位置节点前驱
    DListNode *_getPrior(const size_t &i) {
        DListNode *p = pHead;
        for (size_t j = 0; j < i; j++, p = p->next);
        return p;
    }

public:
    // 默认构造器
    DLinkedList() : m_size(0) {
        pHead = new DListNode();
        pHead->prior = pHead->next = pHead;
    }

    // 析构函数
    ~DLinkedList() {
        pHead->prior->next = nullptr;
        delete pHead;
    }

    // 将C数组构造为双链表
    DLinkedList(T *arr, const size_t &n) : m_size(n), pHead(new DListNode()) {
        pHead->next = pHead->prior = pHead;
        for (int i = 0; i < n; i++)
            append(arr[i]);
    }

    // 拷贝构造
    DLinkedList(const DLinkedList<T> &list) : m_size(list.m_size) {
        _copy(list);
    }

    // 拷贝赋值
    DLinkedList<T> &operator=(const DLinkedList<T> &list) {
        if (&list == this)
            return *this;

        // 将之前申请的内存空间释放
        pHead->prior->next = nullptr;
        delete pHead;

        m_size = list.m_size;
        _copy(list);
    }

    // 指定位置添加元素
    void add(const size_t &i, const T &e) {
        if (i > m_size)
            throw out_of_range("Illegal Index");

        DListNode *p = _getPrior(i);
        _add(p, e);
    }

    // 在链表末尾添加元素
    void append(const T &e) {
        _add(pHead->prior, e);
    }

    // 在链表头部添加元素
    void prepend(const T &e) {
        _add(pHead, e);
    }

    // 删除指定位置的节点
    // 返回元素的引用
    T &remove(const size_t &i) {
        if (i >= m_size)
            throw out_of_range("Illegal Index");
        DListNode *p = _getPrior(i);
        return _remove(p->next);
    }

    // 弹出链表首部的节点
    // 返回元素的引用
    T &popLeft() {
        if (m_size == 0)
            throw out_of_range("Empty List.");
        return _remove(pHead->next);
    }

    // 弹出链表尾部的节点
    // 返回元素的引用
    T &popRight() {
        if (m_size == 0)
            throw out_of_range("Empty List.");
        return _remove(pHead->prior);
    }

    // 获取指定位置的元素引用
    T &get(const size_t &i) {
        if (i >= m_size)
            throw out_of_range("Illegal Index");
        DListNode *p = _getPrior(i);
        return p->next->data;
    }

    // 获取链表元素个数
    const size_t &size() const { return m_size; }

    // 流的插入
    friend ostream &operator<<(ostream &os, const DLinkedList &list) {
        os << "[HEAD<->";
        int i = 0;
        DListNode *p = list.pHead->next;
        for (; p != list.pHead; i++, p = p->next) {
            os << p->data;
            if (list.m_size - 1 != i)
                os << "<->";
        }
        return os << "HEAD]";
    }

};

#endif
