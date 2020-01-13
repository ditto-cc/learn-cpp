
#ifndef _LISTQUEUE_H
#define _LISTQUEUE_H

#include "../List/DLinkedList.h"
#include "Queue.h"

using std::ostream;

template<typename T>
class ListQueue : public Queue<T> {

private:
    DLinkedList<T> *list;

public:
    ListQueue() { list = new DLinkedList<T>(); }

    ~ListQueue() { delete list; }

    void enqueue(const T &e) { list->append(e); }

    T dequeue() {
        if (empty())
            throw "Empty Queue.";
        return list->popleft();
    }

    T getFront() const {
        if (empty())
            throw "Empty Queue.";
        return list->get(0);
    }

    bool empty() const { return list->size() == 0; }

    int size() const { return list->size(); }

    friend ostream &operator<<(ostream &os, const ListQueue<T> &q) {
        return os << "head" << *(q.list) << "tail";
    }

};

#endif