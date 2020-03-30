
#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "../Queue/ListQueue.h"

template <class T>
class BST {
public:
    class BTNode {
    public:
        T data;
        BTNode *lChild, *rChild;

        BTNode(T e, BTNode *l = nullptr, BTNode *r = nullptr) : data(e), lChild(l), rChild(r) {}
        ~BTNode() { delete lChild, rChild; }
    };
private:
    BTNode *m_root;
    int m_size;

    void __preOrder(BTNode *root, void (*visit)(const T &e));
    void __inOrder(BTNode *root, void (*visit)(const T &e));
    void __postOrder(BTNode *root, void (*visit)(const T &e));

    BTNode *__add(BTNode *node, const T &e) {
        if (node == nullptr)
            return new BTNode(e);
        if (node->data < e)
            node->rChild = __add(node->rChild, e);
        else if (node->data > e)
            node->lChild = __add(node->lChild, e);
        return node;
    }

    BTNode *__getNode(BTNode *node, const T &e) {
        if (node == nullptr)
            return nullptr;
        if (node->data < e)
            return __getNode(node->rChild, e);
        else if (node->data > e)
            return __getNode(node->lChild, e);
        return node;
    }

    BTNode *__removeMin(BTNode *node, BTNode *&minNode) {
        if (node == nullptr)
            return nullptr;
        if (node->lChild == nullptr) {
            BTNode *ret = node->rChild;
            node->rChild = nullptr;
            minNode = node;
            return ret;
        }
        node->lChild = __removeMin(node->lChild);
        return node;
    }

    BTNode *__remove(BTNode *node, const T &e) {
        if (!node) return nullptr;

        BTNode *retNode = node;
        if (e < retNode->data)
            retNode->lChild = __remove(retNode->lChild, e);
        else if (e > retNode->rChild)
            retNode->rChild = __remove(retNode->rChild, e);
        else {
            BTNode *delNode = retNode;
            if (!retNode->lChild) {
                retNode = retNode->rChild;
                delNode->rChild = nullptr;
            } else if (!retNode->rChild) {
                retNode = retNode->lChild;
                delNode->lChild = nullptr;
            } else {
                BTNode *successor;
                retNode->rChild = __removeMin(retNode->rChild, successor);
                successor->lChild = retNode->lChild;
                successor->rChild = retNode->rChild;
                retNode->lChild = retNode->rChild = nullptr;
                retNode = successor;
            }
            delete delNode;
        }
        return retNode;
    }

    BTNode *__copy(BTNode *s, BTNode *t) {
        if (!s) return nullptr;
        auto *node = new BTNode(s->data);
        node->lChild = __copy(s->lChild, t->lChild);
        node->rChild = __copy(s->rChild, t->rChild);
        return node;
    }

    int __height(BTNode *node) {
        if (!node) return 0;
        return 1 + std::max(__height(node->lChild), __height(node->rChild));
    }

public:
    BST() : m_root(nullptr), m_size(0) {}
    ~BST() { delete m_root; }

    BST(const BST &tree);
    BST &operator=(const BST &tree);

    int size() { return m_size; }
    bool empty() { return m_size > 0; }
    int height() { return __height(m_root); }
    void add(const T &e) { m_root = __add(m_root, e); }
    bool contains(const T &e) { return __getNode(m_root, e) != nullptr; }
    void remove(const T &e);

    void preOrder(void (*visit)(const T &e)) { __preOrder(visit); }
    void inOrder(void (*visit)(const T &e)) { __inOrder(visit); }
    void postOrder(void (*visit)(const T &e)) { __postOrder(visit); }

    template<class T1>
    friend std::ostream &operator<<(std::ostream &os, BST<T1> &tree) {
        if (tree.empty())
            return os << std::endl;
        int level, h = tree.height();
        ListQueue<BTNode*> q;
        q.enqueue(tree.m_root);
        while (!q.empty() && h > 0) {
            level = q.size();
            h --;
            for (; level > 0; level --) {
                BTNode *front = q.dequeue();
                if (front == nullptr) {
                    os << "NULL ";
                    q.enqueue(nullptr);
                    q.enqueue(nullptr);
                } else {
                    os << front->data << " ";
                    q.enqueue(front->lChild);
                    q.enqueue(front->rChild);
                }
            }
            os << std::endl;
        }
        return os;
    }
};

template<typename T>
void BST<T>::__preOrder(BTNode *root, void (*visit)(const T &e)) {
    if (root == nullptr)
        return;
    visit(root->data);
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
}

template<typename T>
void BST<T>::__inOrder(BTNode *root, void (*visit)(const T &)) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    visit(root->data);
    __preOrder(root->rChild, visit);
}

template<typename T>
void BST<T>::__postOrder(BTNode *root, void (*visit)(const T &)) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
    visit(root->data);
}

template<typename T>
void BST<T>::remove(const T &e) {
    m_root = __remove(m_root, e);
}

template<typename T>
BST<T>::BST(const BST &tree) {
    m_root = __copy(tree.m_root, m_root);
    m_size = tree.m_size;
}

template<typename T>
BST<T> &BST<T>::operator=(const BST &tree) {
    if (&tree == this)
        return *this;

    delete m_root;
    m_size = tree.m_size;
    m_root = __copy(tree.m_root, m_root);
}


#endif