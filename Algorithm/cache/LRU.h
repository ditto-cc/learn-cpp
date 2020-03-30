
#ifndef _LFU_H
#define _LFU_H

#include "../../DataStructure/List/DLinkedList.h"


template <typename K, typename V>
class LFU {

private:
    class Node { K key; V val; };
    DLinkedList<Node> *list;
    int m_capacity;

public:
    LFU(int cap = 10) : m_capacity(cap) { list = new DLinkedList<Node>(); }
    ~LFU() { delete list; }

    V get(K key) {

    }

    void set(K key, V val) {

    }

};


#endif