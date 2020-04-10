
#ifndef _AVL_H
#define _AVL_H

#include <iostream>
#include <functional>
#include "../Queue/ListQueue.h"

using std::range_error;

template <class K, class V>
class AVL {
private:

    class Node {
    public:
        K key;
        V value;
        int height;
        Node *lChild, *rChild;

        Node(K k, V v, int height,
             Node *l = nullptr, Node *r = nullptr):
                key(k), value(v), height(height),
                lChild(l), rChild(r) {}
        ~Node() { delete lChild, rChild; }
    };

    Node *m_root;
    int m_size;
    typedef std::function<void(const K &key, V &value)> visitFunc;

    void __preOrder(Node *root, visitFunc);
    void __inOrder(Node *root, visitFunc);
    void __postOrder(Node *root, visitFunc);

    int getBalanceFactor(Node *node) {
        if (!node) return 0;
        return height(node->lChild) - height(node->rChild);
    }

    Node *leftRotate(Node *node) {
        if (!node) return nullptr;
        Node *rc = node->rChild;
        node->rChild = rc->lChild;
        rc->lChild = node;
        node->height = 1 + std::max(height(node->lChild), height(node->rChild));
        rc->height = 1 + std::max(height(rc->lChild), height(rc->rChild));
        return rc;
    }

    Node *rightRotate(Node *node) {
        if (!node) return nullptr;
        Node *lc = node->lChild;
        node->lChild = lc->rChild;
        lc->rChild = node;
        node->height = 1 + std::max(height(node->lChild), height(node->rChild));
        lc->height = 1+std::max(height(lc->lChild), height(lc->rChild));
        return lc;
    }

    Node *rotate(Node *node) {
        if (!node) return nullptr;

        Node *retNode = node;
        retNode->height = 1 + std::max(height(retNode->lChild), height(retNode->rChild));

        int balanceFactor = getBalanceFactor(retNode);
        if (balanceFactor > -2 && balanceFactor < 2) return retNode;

        int lb = getBalanceFactor(node->lChild), rb = getBalanceFactor(node->rChild);
        if (balanceFactor > 1 && lb >= 0) {
            retNode = rightRotate(retNode);
        } else if (balanceFactor < -1 && rb <= 0) {
            retNode = leftRotate(retNode);
        } else if (balanceFactor > 1 && lb < 0) {
            retNode->lChild = leftRotate(retNode->lChild);
            retNode = rightRotate(retNode);
        } else {
            retNode->rChild = rightRotate(retNode->rChild);
            retNode = leftRotate(retNode);
        }
        return retNode;
    }

    Node *__add(Node *node, const K &key, V &value) {
        if (node == nullptr) {
            m_size++;
            return new Node(key, value, 1);
        }
        if (node->key < key)
            node->rChild = __add(node->rChild, key, value);
        else if (node->key > key)
            node->lChild = __add(node->lChild, key, value);
        else
            node->value = value;
        return rotate(node);
    }

    Node *__getNode(Node *node, const K &key) {
        if (node == nullptr)
            return nullptr;
        if (node->key < key)
            return __getNode(node->rChild, key);
        else if (node->key > key)
            return __getNode(node->lChild, key);
        return node;
    }

    Node *__removeMin(Node *node, Node *&minNode) {
        if (node == nullptr)
            return nullptr;
        if (node->lChild == nullptr) {
            Node *ret = node->rChild;
            node->rChild = nullptr;
            minNode = node;
            return ret;
        }
        node->lChild = __removeMin(node->lChild, minNode);
        return rotate(node);
    }

    Node *__removeMax(Node *node, Node *&maxNode) {
        if (node == nullptr)
            return nullptr;
        if (node->rChild == nullptr) {
            Node *ret = node->lChild;
            node->lChild = nullptr;
            maxNode = node;
            return ret;
        }
        node->rChild = __removeMax(node->rChild, maxNode);
        return rotate(node);
    }

    Node *__remove(Node *node, const K &key) {
        if (!node) return nullptr;
        Node *retNode = node;
        if (key < retNode->key)
            retNode->lChild = __remove(retNode->lChild, key);
        else if (key > retNode->key)
            retNode->rChild = __remove(retNode->rChild, key);
        else {
            Node *delNode = retNode;
            if (!retNode->lChild) {
                retNode = retNode->rChild;
                delNode->rChild = nullptr;
            } else if (!retNode->rChild) {
                retNode = retNode->lChild;
                delNode->lChild = nullptr;
            } else {
                Node *successor;
                retNode->rChild = __removeMin(retNode->rChild, successor);
                successor->lChild = retNode->lChild;
                successor->rChild = retNode->rChild;
                retNode->lChild = retNode->rChild = nullptr;
                retNode = successor;
            }
            delete delNode;
        }
        return rotate(retNode);
    }

    Node *__copy(Node *s, Node *t) {
        if (!s) return nullptr;
        auto *node = new Node(s->key, s->value, s->height);
        node->lChild = __copy(s->lChild, t->lChild);
        node->rChild = __copy(s->rChild, t->rChild);
        return node;
    }

    int height(Node *node) const {
        if (!node) return 0;
        return node->height;
    }

public:
    AVL() : m_root(nullptr), m_size(0) {}
    ~AVL() { delete m_root; }

    AVL(const AVL &tree);
    AVL &operator=(const AVL &tree);

    int size() const { return m_size; }
    bool empty() const { return m_size == 0; }
    int height() const { return height(m_root); }

    void add(const K &key, V &value) { m_root = __add(m_root, key, value); }

    bool contains(const K &key) { return __getNode(m_root, key) != nullptr; }
    V &get(const K &key);
    V &remove(const K &key);

    void preOrder(visitFunc visit) { __preOrder(m_root, visit); }
    void inOrder(visitFunc visit) { __inOrder(m_root, visit); }
    void postOrder(visitFunc visit) { __postOrder(m_root, visit); }

    friend std::ostream &operator<<(std::ostream &os, const AVL<K, V> &tree) {
        if (tree.empty())
            return os << "NULL" <<std::endl;
        int level, h = tree.height();
        ListQueue<Node*> q;
        q.enqueue(tree.m_root);
        while (!q.empty() && h > 0) {
            level = q.size();
            h --;
            for (; level > 0; level --) {
                Node *front = q.dequeue();
                if (front == nullptr) {
                    os << "NULL ";
                    q.enqueue(nullptr);
                    q.enqueue(nullptr);
                } else {
                    os << "(" << front->key << ", " << front->value << ") ";
                    q.enqueue(front->lChild);
                    q.enqueue(front->rChild);
                }
            }
            os << std::endl;
        }
        return os;
    }
};

template<class Key, class Value>
void AVL<Key, Value>::__preOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    visit(root->key, root->value);
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
}

template<class Key, class Value>
void AVL<Key, Value>::__inOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    __inOrder(root->lChild, visit);
    visit(root->key, root->value);
    __inOrder(root->rChild, visit);
}

template<class Key, class Value>
void AVL<Key, Value>::__postOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    __postOrder(root->lChild, visit);
    __postOrder(root->rChild, visit);
    visit(root->key, root->value);
}

template<class Key, class Value>
Value &AVL<Key, Value>::remove(const Key &key) {
    Node *node = __getNode(m_root, key);
    if (!node) throw range_error("Key Error");
    m_root = __remove(m_root, key);
    return node->value;
}

template<class Key, class Value>
Value &AVL<Key, Value>::get(const Key &key) {
    Node *node = __getNode(m_root, key);
    if (!node) throw range_error("Key Error");
    return node->value;
}

template<class Key, class Value>
AVL<Key, Value>::AVL(const AVL &tree) {
    m_root = __copy(tree.m_root, m_root);
    m_size = tree.m_size;
}

template<class Key, class Value>
AVL<Key, Value> &AVL<Key, Value>::operator=(const AVL &tree) {
    if (&tree == this)
        return *this;

    delete m_root;
    m_size = tree.m_size;
    m_root = __copy(tree.m_root, m_root);
}
#endif