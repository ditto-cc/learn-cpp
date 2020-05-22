//
// Created by cheng on 2020/5/23.
//

#ifndef _INSERTIONSORT_H
#define _INSERTIONSORT_H


#include <cstddef>

template<class T>
void insertionSort(T *data, const size_t &n) {
    for (size_t i = 1; i < n; i++) {
        T e = data[i];
        size_t j = i;
        for (; j > 0 && data[j-1] > e; j--)
            data[j] = data[j-1];

        data[j] = e;
    }
}

#endif
