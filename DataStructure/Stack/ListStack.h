
#ifndef _LISTSTACK_H
#define _LISTSTACK_H

#include "../List/LinkedList.h"
#include "Stack.h"

using std::ostream;
using std::out_of_range;

template<class T>
class ListStack : public Stack<T> {
private:
    LinkedList<T> list;

public:
    ListStack() {
        list = LinkedList<T>();
    }

    ~ListStack() = default;

    T pop() {
        if (empty())
            throw out_of_range("Empty Stack.");
        return list.remove(0);
    }

    T &top() const {
        if (empty())
            throw out_of_range("Empty Stack.");
        return list.get(0);
    }

    size_t size() const {
        return list.size();
    }

    bool empty() const {
        return list.empty();
    }

    void push(const T &e) {
        list.prepend(e);
    }

    friend ostream &operator<<(ostream &os, const ListStack &s) {
        return os << "TOP " << s.list << " BOTTOM";
    }
};


#endif