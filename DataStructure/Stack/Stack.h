
#ifndef _STACK_H
#define _STACK_H

template <class T>
class Stack {

public:
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool empty() const = 0;
    virtual int size() const = 0;

};

#endif