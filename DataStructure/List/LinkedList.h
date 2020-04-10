
#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <iostream>

using std::out_of_range;

template<class T>
class LinkedList {
public:
    class ListNode {
    public:
        T data;
        ListNode *next;

        ListNode() : next(nullptr) {}

        explicit ListNode(const T &e, ListNode *next = nullptr) : data(e), next(next) {}

        ~ListNode() { delete next; }
    };

private:
    ListNode *head;
    int size;

    void __copy(const LinkedList<T> &list);

    ListNode *__getPrior(int i) const {
        ListNode *p = head;
        for (int j = 0; j < i; j++)
            p = p->next;
        return p;
    }

public:

    LinkedList() : head(new ListNode()), size(0) {}

    LinkedList(const LinkedList<T> &list);

    LinkedList(int arr[], int n);

    LinkedList<T> &operator=(const LinkedList<T> &list);

    ~LinkedList() { delete head; }

    void add(int i, T e);

    void append(T e) { add(size, e); }

    void prepend(T e) { add(0, e); }

    int getSize() { return size; }

    T remove(int i);

    void set(int i, T e);

    T get(int i) const;

    template<class T1>
    friend std::ostream &operator<<(std::ostream &os, const LinkedList<T1> &list) {
        os << "[";
        int i = 0;
        ListNode *p = list.head->next;
        while (p) {
            os << p->data;
            p = p->next;
            if ((i++) != list.size - 1)
                os << "->";
        }
        return os << "]";
    }
};

template<class T>
inline void LinkedList<T>::__copy(const LinkedList<T> &list) {
    ListNode *p = head;
    ListNode *q = list.head->next;
    while (q) {
        p->next = new ListNode(q->data, nullptr);
        p = p->next;
        q = q->next;
    }
}

template<class T>
inline LinkedList<T>::LinkedList(const LinkedList<T> &list) {
    head = new ListNode();
    size = list.size;
    __copy(list);
}

template<class T>
inline LinkedList<T>::LinkedList(int arr[], int n) : size(0) {
    head = new ListNode();
    for (int i = n - 1; i >= 0; i--)
        prepend(arr[i]);
}

template<class T>
inline LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &list) {
    if (&list == this)
        return *this;
    delete head;
    head = new ListNode();
    size = list.size;
    __copy(list);
    return *this;
}

template<class T>
inline void LinkedList<T>::add(int i, T e) {
    if (i < 0 || i > size)
        throw out_of_range("Add Failed. Illegal Index.");

    ListNode *p = __getPrior(i);
    p->next = new ListNode(e, p->next);
    size++;
}

template<class T>
T LinkedList<T>::remove(int i) {
    if (i < 0 || i >= size)
        throw out_of_range("Remove Failed. Illegal Index.");

    ListNode *p = __getPrior(i);

    ListNode *delNode = p->next;
    T ret = delNode->data;

    p->next = delNode->next;
    delNode->next = nullptr;
    delete delNode;
    size--;
    return ret;
}

template<class T>
void LinkedList<T>::set(int i, T e) {
    if (i < 0 || i >= size)
        throw out_of_range("Set Failed. Illegal Index.");

    ListNode *p = __getPrior(i);
    p->next->data = e;
}

template<class T>
T LinkedList<T>::get(int i) const {
    if (i < 0 || i >= size)
        throw out_of_range("Get Failed. Illegal Index.");

    ListNode *p = __getPrior(i);
    return p->next->data;
}


#endif