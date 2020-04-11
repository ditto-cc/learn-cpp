
#ifndef _AVLSET_H
#define _AVLSET_H

#include "Set.h"
#include "../Tree/AVL.h"

template <class T>
class AVLSet : Set<T> {
private:
    AVL<T, bool> tree;

public:
    AVLSet() { tree = AVL<T, bool>{}; }

    void add(const T &t) override {
        tree.add(t, true);
    }

    bool remove(const T &t) override {
        return tree.remove(t);
    }

    bool contains(const T &t) override {
        return tree.contains(t);
    }

    int size() override {
        return tree.size();
    }

    bool empty() override {
        return tree.empty();
    }

    friend ostream &operator<<(ostream &os, AVLSet<T> &set) {
        set.tree.inOrder([&os](const T &key, bool &val) {
            os << key << ", ";
        });
        return os;
    }
};


#endif
