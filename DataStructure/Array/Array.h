//
// Created by cheng on 2019/12/24.
//

#ifndef _ARRAY_
#define _ARRAY_

#include <iostream>

using std::out_of_range;

template<class T>
class Array {
private:

    // 数据
    T *m_data;
    // 最大容量，当前元素个数
    size_t m_cap, m_len;

    // 从原数组转移到新数组
    // 指定新的最大容量
    void _move(size_t newCapacity) {
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < m_len; i++)
            newData[i] = m_data[i];
        delete[] m_data;
        m_data = newData;
        m_cap = newCapacity;
    }

    // 减少容量
    void _reduceCap() {
        size_t newCapacity = m_cap / 2;
        if (newCapacity == 0)
            return;
        _move(newCapacity);
    }

    // 扩展容量
    void _expandCap() {
        size_t newCapacity = m_cap * 2;
        _move(newCapacity);
    }

public:
    // 构造器，默认初始容量为10
    explicit Array(const size_t &cap = 10) : m_cap(cap), m_len(0) { m_data = new T[cap]; }

    // 拷贝构造函数
    Array(const Array &arr) : m_cap(arr.m_cap), m_len(arr.m_len) {
        m_data = new T[m_cap];
        for (size_t i = 0; i < m_len; i++)
            m_data[i] = arr.m_data[i];
    }

    // 将C数组构造为Array
    Array(T *arr, const size_t &n) : m_cap(sizeof(arr)), m_len(n) {
        m_data = arr;
    }

    // 析构函数
    ~Array() {
        delete[] m_data;
    }

    size_t cap() const {
        return m_cap;
    }

    size_t len() const {
        return m_len;
    }

    // 在指定位置插入元素
    void insert(const size_t &i, const T &e) {
        if (i > m_len)
            throw out_of_range("Illegal Index.");

        if (m_len == m_cap + 1)
            _expandCap();
        for (size_t j = m_len; j > i; j--)
            m_data[j] = m_data[j - 1];
        m_data[i] = e;
        m_len++;
    }

    // 在数组结尾添加元素
    void add(const T &e) {
        insert(m_len, e);
    }

    // 移除指定位置的元素
    // 返回元素
    T remove(const size_t &i) {
        if (i >= m_len)
            throw out_of_range("Illegal Index.");

        if (m_len <= m_cap / 4)
            _reduceCap();

        T ret = m_data[i];
        for (size_t j = i; j < m_len - 1; j++)
            m_data[j] = m_data[j + 1];
        m_len--;
        return ret;
    }

    void set(const size_t &i, const T &e) {
        if (i >= m_len)
            throw out_of_range("Illegal Index.");
        m_data[i] = e;
    }

    T &get(const size_t &i) {
        if (i >= m_len)
            throw out_of_range("Illegal Index.");
        return m_data[i];
    }

    // 数组是否为空
    bool empty() const {
        return m_len == 0;
    }

    Array<T> &operator=(const Array &array) {
        if (this == &array)
            return *this;

        delete[] m_data;

        m_cap = array.cap();
        m_len = array.len();

        m_data = new int[m_cap];
        for (int i = 0; i < m_len; i++)
            m_data[i] = array.m_data[i];
        return *this;
    }

    // 数组下标重载
    T &operator[](const size_t &index) {
        return get(index);
    }

    friend std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
        int size = arr.len();
        os << "[";
        for (int i = 0; i < size; i++) {
            os << arr.m_data[i];
            if (i != size - 1)
                os << ", ";
        }
        return os << "]";
    }
};

template<class T>
size_t len(const Array<T> &arr) {
    return arr.len();
}

template<class T>
size_t cap(const Array<T> &arr) {
    return arr.cap();
}

#endif
