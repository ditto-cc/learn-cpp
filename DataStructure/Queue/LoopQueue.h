
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
    T *m_data;
    size_t m_head, m_tail, m_cap;

    void _move(const size_t &newCapacity) {
        size_t _size = size();
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < _size; i++)
            newData[i] = m_data[(m_head + i) % m_cap];

        delete [] m_data;
        m_data = newData;
        m_cap = newCapacity;
        m_head = 0;
        m_tail = _size;
    }

    void _expandCap() {
        int newCapacity = m_cap * 2;
        _move(newCapacity);
    }

    void _reduceCap() {
        int newCapacity = m_cap / 2;
        if (newCapacity == 0)
            return;
        _move(newCapacity);
    }

public:
    explicit LoopQueue(size_t cap = 10) : m_head(0), m_tail(0), m_cap(cap) {
        m_data = new T[cap];
    }

    ~LoopQueue() {
        delete[] m_data;
    }

    void enqueue(const T &e) {
        if ((m_tail + 1) % m_cap == m_head)
            _expandCap();

        m_data[m_tail] = e;
        m_tail = (m_tail + 1) % m_cap;
    }

    T dequeue() {
        if (empty())
            throw out_of_range("Empty Queue.");

        if (size() <= m_cap / 4)
            _reduceCap();

        T ret = m_data[m_head];
        m_head = (m_head + 1) % m_cap;
        return ret;
    }

    T &front() const {
        if (empty())
            throw out_of_range("Empty Queue.");
        return m_data[m_head];
    }

    bool empty() const {
        return m_tail == m_head;
    }

    size_t size() const {
        return (m_tail - m_head + m_cap) % m_cap;
    }

    friend ostream &operator<<(ostream &os, const LoopQueue<T> &q) {
        os << "HEAD [";
        size_t _size = q.size();
        for (size_t i = 0; i < _size; i++) {
            os << q.m_data[(q.m_head + i) % q.m_cap];
            if (i != _size - 1)
                os << ',' << ' ';
        }
        return os << "] TAIL";
    }
};

#endif