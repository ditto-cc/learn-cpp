
#ifndef _LOOPQUEUE_H
#define _LOOPQUEUE_H

#include "../Array/Array.h"
#include "Queue.h"

template <typename T>
class LoopQueue : Queue<T> {
private:
    T *data;
    int head, tail, m_capacity;

    void __copy(int newCapacity) {
        int _size = size();
        T *newData = new T[newCapacity];
        for (int i = 0; i < _size; i++)
            newData[i] = data[(head + i) % m_capacity];

        delete [] data;
        data = newData;
        m_capacity = newCapacity;
        head = 0; tail = _size;
    }

    void __expandCap() {
        int newCapacity = m_capacity * 2;
        __copy(newCapacity);
    }

    void __reduceCap() {
        int newCapacity = m_capacity / 2;
        if (newCapacity == 0)
            return;
        __copy(newCapacity);
    }

public:
    LoopQueue(int cap = 10) : head(0), tail(0) { data = new T[cap]; }
    ~LoopQueue() { delete data; }

    void enqueue(const T &e) {
        if ((tail + 1) % m_capacity == head)
            __expandCap();
        data[tail] = e;

        tail = (tail + 1) % m_capacity;
    }

    T dequeue() {
        if (empty())
            throw "Empty Queue.";
        T ret = data[head];
        head = (head + 1) % m_capacity;
        return ret;
    }

    T getFront() const {
        if (empty())
            throw "Empty Queue.";
        return data[head];
    }

    bool empty() const { return tail == head; }
    int size() const { return (tail - head + m_capacity) % m_capacity; }

    friend ostream &operator<<(ostream &os, const LoopQueue<T> &q) {
        os << "head[";
        int _size = q.size();
        for (int i = 0; i < _size; i++) {
            os << q.data[(q.head + i) % q.m_capacity];
            if (i != _size - 1)
                os << ", ";
        }
        os << "]tail";
    }
};

#endif