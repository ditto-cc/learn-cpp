//
// Created by cheng on 2019/12/24.
//

#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>

template<class T>
class Array {
private:
    T *data;
    int m_capacity, m_size;

    void __copy(int newCapacity) {
        T *newData = new T(newCapacity);
        for (int i = 0; i < m_size; i++)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        m_capacity = newCapacity;
    }

    void __reduceCap() {
        int newCapacity = m_capacity / 2;
        if (newCapacity == 0)
            return;
        __copy(newCapacity);
    }

    void __expandCap() {
        int newCapacity = m_capacity * 2;
        T *newData = new T(newCapacity);
        __copy(newCapacity);
    }

public:
    Array(const int &cap = 10) : m_capacity(cap), m_size(0) { data = new int[cap]; }

    Array(const Array &arr) : m_capacity(arr.capacity()), m_size(arr.capacity()) {
        data = new int[m_capacity];
        for (int i = 0; i < m_size; i++)
            data[i] = arr.data[i];
    }

    Array<T> &operator=(const Array &array);

    ~Array() { delete[] data; }

    int capacity() const { return m_capacity; }

    int size() const { return m_size; }

    void add(int i, const T &e) {
        if (i < 0 || i > m_size)
            throw "Illegal Index.";

        if (m_size == m_capacity + 1)
            __expandCap();
        for (int j = m_size; j > i; j--)
            data[j] = data[j - 1];
        data[i] = e;
        m_size++;
    }

    T remove(int i) {
        if (i < 0 || i >= m_size)
            throw "Illegal Index.";

        if (m_size <= m_capacity / 4)
            __reduceCap();

        T ret = data[i];
        for (int j = i; j < m_size - 1; j++)
            data[j] = data[j + 1];
        m_size--;
        return ret;
    }

    void set(int i, const T &e) {
        if (i < 0 || i >= m_size)
            throw "Illegal Index.";
        data[i] = e;
    }

    T get(int i) const {
        if (i < 0 || i >= m_size)
            throw "Illegal Index.";
        return data[i];
    }


};

template<class T>
Array<T> &Array<T>::operator=(const Array &array) {
    if (this == &array)
        return *this;

    delete[] data;

    m_capacity = array.capacity();
    m_size = array.size();

    data = new int[m_capacity];
    for (int i = 0; i < m_size; i++)
        data[i] = array.data[i];
    return *this;
}

template<class T>
inline std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
    int capacity = arr.capacity();
    int size = arr.size();
    os << "[";
    for (int i = 0; i < size; i++) {
        os << arr.get(i);
        if (i != size - 1)
            os << ", ";
    }
    return os << "]";
}


#endif
