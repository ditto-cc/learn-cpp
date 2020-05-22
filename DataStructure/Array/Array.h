//
// Created by cc on 2019/12/24.
//

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <cstring>

using std::out_of_range;

template<class T>
class Array {
private:

    // 数据
    T *m_data;
    // 最大容量，当前元素个数
    size_t m_cap, m_size;

    // 从原数组转移到新数组
    // 指定新的最大容量
    void _move(size_t newCapacity) {
        T *newData = new T[newCapacity];
        for (size_t i = 0; i < m_size; i++)
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
        _move(m_cap * 2);
    }

    // 根据给定数组数据拷贝到当前实例
    void _copy(const Array<T> &arr) {
        m_data = new T[m_cap];
        for (size_t i = 0; i < m_size; i++)
            m_data[i] = arr.m_data[i];
    }

public:
    Array() : m_cap(1), m_size(0) {
        m_data = new T[1];
    }

    // 构造器，默认初始容量为10
    explicit Array(const size_t &cap = 10) : m_cap(cap), m_size(0) {
        m_data = new T[cap];
    }

    // 拷贝构造函数
    Array(const Array &arr) : m_cap(arr.m_cap), m_size(arr.m_size) {
        _copy(arr);
    }

    // 将C数组构造为Array
    Array(T *arr, const size_t &n) : m_cap(n), m_size(n), m_data(arr) {}

    // 析构函数
    ~Array() {
        delete[] m_data;
    }

    size_t cap() const {
        return m_cap;
    }

    size_t size() const {
        return m_size;
    }

    // 在指定位置插入元素
    void insert(const size_t &i, const T &e) {
        if (i > m_size)
            throw out_of_range("Illegal Index.");

        if (m_size == m_cap + 1)
            _expandCap();
        for (size_t j = m_size; j > i; j--)
            m_data[j] = m_data[j - 1];
        m_data[i] = e;
        m_size++;
    }

    // 在数组结尾添加元素
    void add(const T &e) {
        insert(m_size, e);
    }

    // 移除指定位置的元素
    // 返回元素
    T remove(const size_t &i) {
        if (i >= m_size)
            throw out_of_range("Illegal Index.");

        if (m_size <= m_cap / 4)
            _reduceCap();

        T ret = m_data[i];
        for (size_t j = i; j < m_size - 1; j++)
            m_data[j] = m_data[j + 1];
        m_size--;
        return ret;
    }

    // 将指定位置元素设置为e
    void set(const size_t &i, const T &e) {
        if (i >= m_size)
            throw out_of_range("Illegal Index.");
        m_data[i] = e;
    }

    // 获取指定位置元素引用
    T &get(const size_t &i) const {
        if (i >= m_size)
            throw out_of_range("Illegal Index.");
        return m_data[i];
    }

    // 数组是否为空
    bool empty() const {
        return m_size == 0;
    }

    // 拷贝复制
    Array<T> &operator=(const Array &arr) {
        if (this == &arr)
            return *this;

        delete[] m_data;

        m_cap = arr.cap();
        m_size = arr.size();

        _copy(arr);
        return *this;
    }

    // 数组下标重载
    T &operator[](const size_t &index) const {
        return get(index);
    }

    // 流插入重载
    friend std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
        int size = arr.size();
        os << "[";
        for (int i = 0; i < size; i++) {
            os << arr.m_data[i];
            if (i != size - 1)
                os << ", ";
        }
        return os << "]";
    }
};

#endif
