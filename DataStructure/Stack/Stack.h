
#ifndef _STACK_H
#define _STACK_H

#include <cstdlib>

template <class T>
class Stack {

public:
    virtual ~Stack() = default;

    virtual void push(const T &e) = 0;
    virtual T pop() = 0;
    virtual T &top() = 0;
    virtual bool empty() const = 0;
    virtual size_t size() const = 0;

};

#endif