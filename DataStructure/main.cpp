#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Array/Array.h"
#include "List/LinkedList.h"
#include "List/DLinkedList.h"
#include "Queue/ListQueue.h"
#include "Queue/LoopQueue.h"
#include "Stack/ArrayStack.h"
#include "Stack/ListStack.h"
#include "Tree/AVL.h"
#include "Tree/BST.h"
#include "Tree/RBT.h"
#include "Tree/Trie.h"
#include "Entity/Student.h"
#include "Map/AVLMap.h"
#include "Set/AVLSet.h"
#include "Graph/MGraph.h"
#include "Graph/AGraph.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    // int n = 10;
    // MGraph<int> mGraph(n, false);
    // cout << mGraph << endl;
    // for (size_t i = 0; i < n; i++) {
    //     for (size_t j = i + 1; j < n; j++) {
    //         mGraph.addEdge(i, j);
    //     }
    // }
    // cout << mGraph << endl;

    Array<Student> arr;
    cout << arr << endl;
    for (size_t i = 0; i < 50; i++) {
        Student student = Student("cc", i);
        arr.add(student);
        cout << arr << endl;
    }
    arr[4].name("dd");
    cout << arr;
    return 0;
}