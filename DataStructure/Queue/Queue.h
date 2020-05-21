
#ifndef _QUEUE_H
#define _QUEUE_H

template <class T>
class Queue {
public:
    virtual ~Queue() = default;

    virtual void enqueue(const T &e) = 0;
    virtual T dequeue() = 0;
    virtual T &front() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
};


#endif