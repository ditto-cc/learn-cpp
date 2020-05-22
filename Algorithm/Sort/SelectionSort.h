//
// Created by cheng on 2020/5/23.
//

#ifndef _SELECTIONSORT_H
#define _SELECTIONSORT_H


#include <cstddef>
#include "SortUtil.h"

template<class T>
void selectionSort(T *data, const size_t &n) {
    for (size_t i = 0; i < n; i++) {
        size_t min = i;
        for (size_t j = min + 1; j < n; j++) {
            if (data[j] < data[min])
                min = j;
        }
        SortUtil::swap(data, min, i);
    }
}

#endif
