
#ifndef _ARRAYSTACK_H
#define _ARRAYSTACK_H

#include "../Array/Array.h"
#include "Stack.h"

using std::ostream;
using std::exception;
using std::out_of_range;

template<class T>
class ArrayStack : public Stack<T> {
private:
    Array<T> *arr;

public:
    ArrayStack() { arr = new Array<T>(); }

    ~ArrayStack() { delete arr; }

    void push(T e) { arr->add(arr->size(), e); }

    T pop() {
        if (empty())
            throw out_of_range("Empty Stack.");
        return arr->remove(arr->size() - 1);
    }

    T top() const {
        if (empty())
            throw out_of_range("Empty Stack.");
        return arr->get(arr->size() - 1);
    }

    bool empty() const { return arr->size() == 0; }

    int size() const { return arr->size(); }

    friend ostream &operator<<(ostream &os, const ArrayStack<T> &s) {
        return os << "bottom" << *(s.arr) << "top";
    }
};


#endif