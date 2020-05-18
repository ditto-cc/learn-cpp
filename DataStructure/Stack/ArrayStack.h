
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
    Array<T> arr;

public:
    explicit ArrayStack(int cap = 10) { arr = Array<T>(cap); }

    ~ArrayStack() = default;

    void push(const T &e) {
        arr.add(e);
    }

    T pop() {
        if (empty())
            throw out_of_range("Empty Stack.");
        return arr.remove(arr.size() - 1);
    }

    T &top() {
        if (empty())
            throw out_of_range("Empty Stack.");
        return arr[arr.size() - 1];
    }

    bool empty() const {
        return arr.empty();
    }

    const size_t &size() const {
        return arr.size();
    }

    friend ostream &operator<<(ostream &os, const ArrayStack<T> &s) {
        return os << "bottom" << s.arr << "top";
    }
};


#endif