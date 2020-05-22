//
// Created by cheng on 2020/5/23.
//

#ifndef _BUBBLESORT_H
#define _BUBBLESORT_H


#include <cstddef>
#include "SortUtil.h"

template<class T>
void bubbleSort(T *data, const size_t &n) {
    bool hasChange;

    do {
        hasChange = false;
        for (size_t i = n - 1; i > 0; i--) {
            for (size_t j = 0; j < i; j++) {
                if (data[j] > data[j+1]) {
                    SortUtil::swap(data, j, j + 1);
                    hasChange = true;
                }
            }
        }
    } while (hasChange);

}

#endif
