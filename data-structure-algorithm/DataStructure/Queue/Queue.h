
#ifndef _QUEUE_H
#define _QUEUE_H

template <class T>
class Queue {
public:
    virtual void enqueue(const T &e) = 0;
    virtual T dequeue() = 0;
    virtual T getFront() const = 0;
    virtual int size() const = 0;
    virtual bool empty() const = 0;
};


#endif