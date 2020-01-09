cmake_minimum_required(VERSION 3.13)
project(data_structure_algorithm_cpp)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        data_structure_algorithm_cpp main.cpp


        DataStructure/Array/Array.h

        DataStructure/List/LinkedList.h
        DataStructure/List/DLinkedList.h

        DataStructure/Stack/Stack.h
        DataStructure/Stack/ArrayStack.h
        DataStructure/Stack/ListStack.h

        DataStructure/Queue/Queue.h
        DataStructure/Queue/ListQueue.h
        DataStructure/Queue/LoopQueue.h

        DataStructure/Tree/BST.h
        DataStructure/Tree/RBT.h
        DataStructure/Tree/AVL.h
        DataStructure/Tree/Trie.h

        DataStructure/Graph/AGraph.h
        DataStructure/Graph/MGraph.h
)