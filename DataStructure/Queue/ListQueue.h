
#ifndef _LISTQUEUE_H
#define _LISTQUEUE_H

#include "../List/DLinkedList.h"
#include "Queue.h"

using std::ostream;
using std::out_of_range;

template<class T>
class ListQueue : public Queue<T> {

private:
    DLinkedList<T> list;

public:
    ListQueue() {
        list = DLinkedList<T>();
    }

    ~ListQueue() = default;

    void enqueue(const T &e) {
        list.append(e);
    }

    T dequeue() {
        if (empty())
            throw out_of_range("Empty Queue.");
        return list.popLeft();
    }

    T &front() const {
        if (empty())
            throw out_of_range("Empty Queue.");
        return list.get(0);
    }

    bool empty() const {
        return list.empty();
    }

    size_t size() const {
        return list.size();
    }

    friend ostream &operator<<(ostream &os, const ListQueue<T> &q) {
        return os << "HEAD " << q.list << " TAIL";
    }

};

#endif