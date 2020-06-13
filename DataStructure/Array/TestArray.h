
#ifndef _TESTARRAY_H
#define _TESTARRAY_H

#include <iostream>
#include "Array.h"

using std::cout;
using std::endl;


namespace TestArray {
    const unsigned int SIZE = 25;

    void testArray() {
        Array<int> arr;

        cout << "Add Element." << endl;
        for (unsigned int i = 0; i < SIZE; i++) {
            cout << arr << endl;
            arr.add(i);
        }
        cout << "Add Completed." << endl;
        cout << "Array<int> " << arr << endl;

        cout << "Remove arr[10]" << endl;
        arr.remove(10);
        cout << "Array<int> " << arr << endl;

        cout << "Get arr[2] Reference." << endl;
        int &e = arr[2];
        cout << "Modify arr[2] Reference to 100" << endl;
        e = 100;
        cout << "Array<int> arr = " << arr << endl;

        cout << "Remove All Elements From Tail." << endl;
        while (!arr.empty()) {
            arr.remove(arr.size()-1);
            cout << "Array<int> " << arr << endl;
        }
    }
}

#endif
