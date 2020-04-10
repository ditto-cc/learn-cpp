
#ifndef _AVLMAP_
#define _AVLMAP_

#include "../Tree/AVL.h"
#include "Map.h"

template <class K, class V>
class AVLMap : Map<K, V> {
private:
    AVL<K, V> tree;

public:
    void put(const K &key, V &val) override {
        tree.add(key, val);
    }

    bool contains(const K &key) override {
        return tree.contains(key);
    }

    V &remove(const K &key) override {
        return tree.remove(key);
    }

    V &get(const K &key) override {
        return tree.get(key);
    }

    int size() const override {
        return tree.size();
    }

    bool empty() const override {
        return tree.empty();
    }

    friend ostream &operator<<(ostream &os, AVLMap<K, V> &map) {
        map.tree.inOrder([&os](const K &key, V &val) {
            os << "(" << key << ", " << val << ")";
        });
        return os;
    }
};

#endif