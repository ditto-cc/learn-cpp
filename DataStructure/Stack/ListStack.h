
#ifndef _LISTSTACK_H
#define _LISTSTACK_H

#include "../List/LinkedList.h"
#include "Stack.h"

using std::ostream;
using std::out_of_range;

template<class T>
class ListStack : public Stack<T> {
private:
    LinkedList<T> *list;

public:
    ListStack() { list = new LinkedList<T>(); }

    ~ListStack() { delete list; }

    T pop() {
        if (empty())
            throw out_of_range("Empty Stack.");
        return list->remove(0);
    }

    T top() const {
        if (empty())
            throw out_of_range("Empty Stack.");
        return list->get(0);
    }

    int size() const { return list->getSize(); }

    bool empty() const { return list->getSize() == 0; }

    void push(T e) { list->prepend(e); }

    friend ostream &operator<<(ostream &os, const ListStack &s) {
        return os << "top" << *(s.list) << "bottom";
    }
};


#endif