//
// Created by cheng on 2020/5/23.
//

#ifndef _UTIL_H
#define _UTIL_H

#include <cstddef>

namespace SortUtil {

    template<class T>
    void swap(T *data, const size_t &i, const size_t &j) {
        T e = data[i];
        data[i] = data[j];
        data[j] = e;
    }
}

#endif
