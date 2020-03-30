
#ifndef _DLINKEDLIST_
#define _DLINKEDLIST_

#include <iostream>
#include "LinkedList.h"

using std::ostream;

template<class T>
class DLinkedList {
public:
    class DListNode {
    public:
        T data;
        DListNode *next, *prior;

        DListNode() : prior(nullptr), next(nullptr) {}

        DListNode(T e, DListNode *p = nullptr, DListNode *n = nullptr) : data(e), prior(p), next(n) {}

        ~DListNode() { delete next; }
    };

private:
    DListNode *head;
    int m_size;

    void __add(DListNode *p, T e);

    T __remove(DListNode *p);

public:
    DLinkedList() : m_size(0) {
        head = new DListNode();
        head->prior = head->next = head;
    }

    ~DLinkedList() {
        head->prior->next = nullptr;
        head->prior = nullptr;
        delete head;
}

    DLinkedList(T *arr, int n);

    DLinkedList(const DLinkedList<T> &arr);

    DLinkedList<T> &operator=(const DLinkedList<T> &list);

    void add(int i, T e);

    void append(T e);

    void prepend(T e);

    T remove(int i);

    T popleft();

    T popright();

    T get(int i);

    int size() { return m_size; }

    friend ostream &operator<<(ostream &os, const DLinkedList &list) {
        os << "[";
        int i = 0;
        DListNode *p = list.head->next;
        for (; p != list.head; i++, p = p->next) {
            os << p->data;
            if (list.m_size - 1 != i)
                os << "<->";
        }

        return os << "]";
    }

};

template<class T>
DLinkedList<T>::DLinkedList(T *arr, int n) {
    head = new DListNode();
    head->next = head;
    head->prior = head;
    for (int i = 0; i < n; i++)
        append(arr[i]);
}

template<class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &list) {
    m_size = list.m_size;
    head = new DListNode();
    head->next = head->prior = head;
    DListNode *p = list.head->next;
    while (p != list.head) {
        append(p->data);
        p = p->next;
    }
}

template<class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list) {
    if (&list == this)
        return *this;
    head->prior->next = nullptr;
    head->prior = nullptr;
    delete head;
    m_size = list.m_size;
    head = new DListNode();
    head->next = head->prior = head;
    DListNode *p = list.head->next;
    while (p != list.head) {
        append(p->data);
        p = p->next;
    }
}

template<class T>
inline void DLinkedList<T>::__add(DLinkedList::DListNode *p, T e) {
    DListNode *node = new DListNode(e, p, p->next);
    p->next->prior = node;
    p->next = node;
    m_size++;
}

template<class T>
inline T DLinkedList<T>::__remove(DLinkedList::DListNode *p) {
    T ret = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    p->next = p->prior = nullptr;
    delete p;
    m_size--;
    return ret;
}

template<class T>
inline void DLinkedList<T>::add(int i, T e) {
    if (i < 0 || i > m_size)
        throw "Illegal Index";

    DListNode *p = head;
    for (int j = 0; j < i; j++, p = p->next);
    __add(p, e);
}

template<class T>
inline void DLinkedList<T>::append(T e) {
    __add(head->prior, e);
}

template<class T>
inline void DLinkedList<T>::prepend(T e) {
    __add(head, e);
}

template<class T>
inline T DLinkedList<T>::remove(int i) {
    if (i < 0 || i >= m_size)
        throw "Illegal Index";
    DListNode *p = head->next;
    for (int j = 0; j < i; j++, p = p->next);
    return __remove(p);
}

template<class T>
inline T DLinkedList<T>::popleft() {
    if (m_size == 0)
        throw "Empty List.";
    return __remove(head->next);
}

template<class T>
inline T DLinkedList<T>::popright() {
    if (m_size == 0)
        throw "Empty List.";
    return __remove(head->prior);
}

template<class T>
T DLinkedList<T>::get(int i) {
    if (i < 0 || i >= m_size)
        throw "Illegal Index";
    DListNode *p = head;
    for (int j = 0; j < i; j++, p = p->next);
    return p->next->data;
}

#endif
