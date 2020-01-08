#include <iostream>
#include "Algorithm/Sort/SortTestHelper.h"
#include "Algorithm/Sort/InsertionSort.h"
#include "Algorithm/Sort/SelectionSort.h"
#include "Algorithm/Sort/BubbleSort.h"

#include "DataStructure/Array/Array.h"
#include "DataStructure/List/LinkedList.h"
#include "DataStructure/List/DLinkedList.h"
#include "DataStructure/Queue/ListQueue.h"
#include "DataStructure/Queue/LoopQueue.h"
#include "DataStructure/Stack/ArrayStack.h"
#include "DataStructure/Stack/ListStack.h"

using namespace SortTestHelper;
using std::cout;
using std::endl;

int main() {
//    int n = 10000;
//    int *arr_insertion_test = generateRandomArray(n, 0, n);
//    int *arr_selection_test = copyIntArray(arr_insertion_test, n);
//    int *arr_bubble_test = copyIntArray(arr_insertion_test, n);
//    testSort("Insertion Sort", insertionSort, arr_insertion_test, n);
//    testSort("Selection Sort", selectionSort, arr_selection_test, n);
//    testSort("Bubble Sort", bubbleSort, arr_bubble_test, n);


//    Array<int> array(5);
//    cout << array << endl;
//
//    for (int i = 1; i < 11; i++) {
//        array.add(i - 1, i - 1);
//        cout << array << endl;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        cout << array.remove(0) << endl;
//        cout << array << endl;
//    }

    int arr[10];
    for (int i = 0; i < 10; i ++)
        arr[i] = i;

    auto q = LoopQueue<int>();
    for (int i = 0; i < 10; i++) {
        q.enqueue(arr[i]);
        cout << q << endl;
        if (i % 3 == 1)
            cout << q.dequeue() << endl;
    }
    return 0;
}