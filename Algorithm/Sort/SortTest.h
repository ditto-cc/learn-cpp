//
// Created by cheng on 2020/5/23.
//

#ifndef _SORTTESTHELPER_H
#define _SORTTESTHELPER_H

#include <cstddef>
#include <iostream>
#include <cassert>
#include <random>
#include "SortUtil.h"

namespace SortTest {

    using std::cout;
    using std::endl;
    using std::uniform_int_distribution;
    using std::random_device;
    using std::mt19937;
    using std::swap;


    int *genRandomArray(const size_t &n, int l, int r) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> u(l, r);
        int *arr = new int[n];
        for (size_t i = 0; i < n; i++)
            arr[i] = u(gen);
        return arr;
    }

    int *genNearlyOrderedArray(const size_t &n, const size_t &swapTimes) {
        int *arr = new int[n];
        for (size_t i = 0; i < n; i++)
            arr[i] = i;

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> u(0, n);
        for (size_t i = swapTimes; i > 0; i--)
            SortUtil::swap(arr, u(gen), u(gen));
        return arr;
    }

    int *copyArray(const int *src, const size_t &n) {
        int *arr = new int[n];
        memcpy(arr, src, n * sizeof(int));
        return arr;
    }

    int *printArray(const int *arr, const size_t &n) {
        cout << '[';
        for (size_t i = 0; i < n; i++) {
            cout << arr[i];
            if (i < n - 1)
                cout << ',' << ' ';
        }
        cout << ']' << endl;
    }

    template<class T>
    void testSorted(T *data, const size_t &n) {
        for (size_t i = 1; i < n; i++)
            assert(data[i - 1] <= data[i]);
        cout << "Test Completed. Data is Sorted." << endl;
    }
}

#endif
