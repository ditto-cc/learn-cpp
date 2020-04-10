
#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "../Queue/ListQueue.h"

template <class K, class V>
class BST {
private:
    class Node {
    public:
        K key;
        V value;
        Node *lChild, *rChild;

        explicit Node(K key, V val, Node *l = nullptr, Node *r = nullptr) : key(key), value(val), lChild(l), rChild(r) {}
        ~Node() { delete lChild, rChild; }
    };

    Node *m_root;
    int m_size;
    typedef std::function<void(const K &key, V &value)> visitFunc;

    void __preOrder(Node *root, visitFunc);
    void __inOrder(Node *root, visitFunc);
    void __postOrder(Node *root, visitFunc);

    Node *__add(Node *node, const K &key, const V &val) {
        if (node == nullptr) {
            m_size++;
            return new Node(key, val);
        }
        if (node->key < key)
            node->rChild = __add(node->rChild, key, val);
        else if (node->key > key)
            node->lChild = __add(node->lChild, key, val);
        else
            node->value = val;
        return node;
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
            m_size--;
            return ret;
        }
        node->lChild = __removeMin(node->lChild, minNode);
        return node;
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
                m_size--;
            } else if (!retNode->rChild) {
                retNode = retNode->lChild;
                delNode->lChild = nullptr;
                m_size--;
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
        return retNode;
    }

    Node *__copy(Node *s, Node *t) {
        if (!s) return nullptr;
        auto *node = new Node(s->key, s->value);
        node->lChild = __copy(s->lChild, t->lChild);
        node->rChild = __copy(s->rChild, t->rChild);
        return node;
    }

    int __height(Node *node) const {
        if (!node) return 0;
        return 1 + std::max(__height(node->lChild), __height(node->rChild));
    }

public:
    BST() : m_root(nullptr), m_size(0) {}
    ~BST() { delete m_root; }

    BST(const BST &tree);
    BST &operator=(const BST &tree);

    int size() const { return m_size; }
    bool empty() const { return m_size > 0; }
    int height() const { return __height(m_root); }
    void add(const K &key, const V &val) { m_root = __add(m_root, key, val); }
    bool contains(const K &e) { return __getNode(m_root, e) != nullptr; }
    V &remove(const K &key);
    V &get(const K &key);

    void preOrder(void (*visit)(const K &key, const V &val)) { __preOrder(visit); }
    void inOrder(void (*visit)(const K &key, const V &val)) { __inOrder(visit); }
    void postOrder(void (*visit)(const K &key, const V &val)) { __postOrder(visit); }

    template<class K1, class V1>
    friend std::ostream &operator<<(std::ostream &os, const BST<K1, V1> &tree) {
        if (tree.empty())
            return os << std::endl;
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
                    os << front->key << " ";
                    q.enqueue(front->lChild);
                    q.enqueue(front->rChild);
                }
            }
            os << std::endl;
        }
        return os;
    }
};

template<class K, class V>
void BST<K, V>::__preOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    visit(root->data);
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
}

template<class K, class V>
void BST<K, V>::__inOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    visit(root->data);
    __preOrder(root->rChild, visit);
}

template<class K, class V>
void BST<K, V>::__postOrder(Node *root, visitFunc visit) {
    if (root == nullptr)
        return;
    __preOrder(root->lChild, visit);
    __preOrder(root->rChild, visit);
    visit(root->data);
}

template<class K, class V>
V &BST<K, V>::remove(const K &key) {
    auto node = __getNode(m_root, key);
    if (node == nullptr) {
        throw std::range_error("Key Error.");
    }
    m_root = __remove(m_root, key);
    return node->value;
}

template<class K, class V>
V &BST<K, V>::get(const K &key)  {
    auto node = __getNode(m_root, key);
    if (node == nullptr) {
        throw std::range_error("Key Error.");
    }
    return node->value;
}

template<class K, class V>
BST<K, V>::BST(const BST &tree) {
    m_root = __copy(tree.m_root, m_root);
    m_size = tree.m_size;
}

template<class K, class V>
BST<K, V> &BST<K, V>::operator=(const BST &tree) {
    if (&tree == this)
        return *this;

    delete m_root;
    m_size = tree.m_size;
    m_root = __copy(tree.m_root, m_root);
}


#endif