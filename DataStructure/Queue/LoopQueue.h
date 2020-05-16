
#ifndef _LOOPQUEUE_H
#define _LOOPQUEUE_H

#include <iostream>
#include "../Array/Array.h"
#include "Queue.h"

using std::out_of_range;
using std::ostream;

template <class T>
class LoopQueue : Queue<T> {
private:
    T *data;
    int head, tail, m_cap{};

    void _copy(int newCapacity) {
        size_t _size = size();
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < _size; i++)
            newData[i] = data[(head + i) % m_cap];

        delete [] data;
        data = newData;
        m_cap = newCapacity;
        head = 0; tail = _size;
    }

    void _expandCap() {
        int newCapacity = m_cap * 2;
        _copy(newCapacity);
    }

    void _reduceCap() {
        int newCapacity = m_cap / 2;
        if (newCapacity == 0)
            return;
        _copy(newCapacity);
    }

public:
    explicit LoopQueue(int cap = 10) : head(0), tail(0) {
        data = new T[cap];
    }

    ~LoopQueue() {
        delete data;
    }

    void enqueue(const T &e) {
        if ((tail + 1) % m_cap == head)
            _expandCap();
        data[tail] = e;

        tail = (tail + 1) % m_cap;
    }

    T dequeue() {
        if (empty())
            throw out_of_range("Empty Queue.");

        if (size() < m_cap / 4)
            _reduceCap();

        T ret = data[head];
        head = (head + 1) % m_cap;
        return ret;
    }

    T &getFront() {
        if (empty())
            throw out_of_range("Empty Queue.");
        return data[head];
    }

    bool empty() const {
        return tail == head;
    }

    size_t size() const {
        return (tail - head + m_cap) % m_cap;
    }

    friend ostream &operator<<(ostream &os, const LoopQueue<T> &q) {
        os << "HEAD[";
        int _size = q.size();
        for (int i = 0; i < _size; i++) {
            os << q.data[(q.head + i) % q.m_cap];
            if (i != _size - 1)
                os << ',' << ' ';
        }
        os << "]TAIL";
    }
};

#endif