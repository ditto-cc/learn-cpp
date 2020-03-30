
#ifndef _AVL_H
#define _AVL_H
#include <iostream>
#include "../Queue/ListQueue.h"

template <class Key, class Value>
class AVL {
private:
    class Node {
    public:
        Key key;
        Value value;
        int height;
        Node *lChild, *rChild;

        Node(Key k, Value v, int height,
                Node *l = nullptr, Node *r = nullptr):
                key(k), value(v), height(height),
                lChild(l), rChild(r) {}
        ~Node() { delete lChild, rChild; }
    };
    Node *m_root;
    int m_size;

    void __preOrder(Node *root, void (*visit)(const Key &key, Value &value));
    void __inOrder(Node *root, void (*visit)(const Key &key, Value &value));
    void __postOrder(Node *root, void (*visit)(const Key &key, Value &value));

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

    Node *__add(Node *node, const Key &key, Value &value) {
        if (node == nullptr)
            return new Node(key, value, 1);
        if (node->key < key)
            node->rChild = __add(node->rChild, key, value);
        else if (node->key > key)
            node->lChild = __add(node->lChild, key, value);
        return rotate(node);
    }

    Node *__getNode(Node *node, const Key &key) {
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
        node->lChild = __removeMin(node->lChild);
        return rotate(node);
    }

    Node *__remove(Node *node, const Key &key) {
        if (!node) return nullptr;
        Node *retNode = node;
        if (key < retNode->key)
            retNode->lChild = __remove(retNode->lChild, key);
        else if (key > retNode->rChild)
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
        auto *node = new Node(s->key);
        node->lChild = __copy(s->lChild, t->lChild);
        node->rChild = __copy(s->rChild, t->rChild);
        return node;
    }

    int height(Node *node) {
        if (!node) return 0;
        return node->height;
    }

public:
    AVL() : m_root(nullptr), m_size(0) {}
    ~AVL() { delete m_root; }

    AVL(const AVL &tree);
    AVL &operator=(const AVL &tree);

    int size() { return m_size; }
    bool empty() { return m_size == 0; }
    int height() { return height(m_root); }

    void add(const Key &key, Value &value) {
        Node *node = __getNode(m_root, key);
        if (node) {
            node->value = value;
        } else {
            m_root = __add(m_root, key, value);
            m_size++;
        }
    }

    bool contains(const Key &key) { return __getNode(m_root, key) != nullptr; }
    void remove(const Key &key);

    void preOrder(void (*visit)(const Key &key, Value &value)) { __preOrder(visit); }
    void inOrder(void (*visit)(const Key &key, Value &value)) { __inOrder(visit); }
    void postOrder(void (*visit)(const Key &key, Value &value)) { __postOrder(visit); }

    template<class K, class V>
    friend std::ostream &operator<<(std::ostream &os, AVL<K, V> &tree) {
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
void AVL<Key, Value>::__preOrder(Node *root, void (*visit)(const Key &key, Value &value)) {
    if (root == nullptr)
        return;
    visit(root->key);
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
}

template<class Key, class Value>
void AVL<Key, Value>::__inOrder(Node *root, void (*visit)(const Key &key, Value &value)) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    visit(root->key);
    __preOrder(root->rChild, visit);
}

template<class Key, class Value>
void AVL<Key, Value>::__postOrder(Node *root, void (*visit)(const Key &key, Value &value)) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
    visit(root->key);
}

template<class Key, class Value>
void AVL<Key, Value>::remove(const Key &key) {
    m_root = __remove(m_root, key);
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