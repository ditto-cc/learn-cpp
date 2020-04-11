
#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "../Queue/ListQueue.h"

template<class K, class V>
class BST {
private:
    class Node {
    public:
        K key;
        V value;
        Node *lChild, *rChild;

        explicit Node(K key, V val,
                Node *l = nullptr, Node *r = nullptr):
                key(key), value(val),
                lChild(l), rChild(r) {}

        ~Node() { delete lChild, rChild; }
    };

    Node *m_root;
    int m_size;
    typedef std::function<void(const K &key, V &value)> visitFunc;

    void preOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        visit(root->data);
        preOrder(root->lChild, visit);
        preOrder(root->rChild, visit);
    }

    void inOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        inOrder(root->lChild, visit);
        visit(root->data);
        inOrder(root->rChild, visit);
    }

    void postOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        postOrder(root->lChild, visit);
        visit(root->data);
        postOrder(root->rChild, visit);
    }

    Node *add(Node *node, const K &key, V val) {
        if (node == nullptr) {
            m_size++;
            return new Node(key, val);
        }
        if (node->key < key)
            node->rChild = add(node->rChild, key, val);
        else if (node->key > key)
            node->lChild = add(node->lChild, key, val);
        else
            node->value = val;
        return node;
    }

    Node *getNode(Node *node, const K &key) {
        if (node == nullptr)
            return nullptr;
        if (node->key < key)
            return getNode(node->rChild, key);
        else if (node->key > key)
            return getNode(node->lChild, key);
        return node;
    }

    Node *removeMin(Node *node, Node *&minNode) {
        if (node == nullptr)
            return nullptr;
        if (node->lChild == nullptr) {
            Node *ret = node->rChild;
            node->rChild = nullptr;
            minNode = node;
            m_size--;
            return ret;
        }
        node->lChild = removeMin(node->lChild, minNode);
        return node;
    }

    Node *remove(Node *node, const K &key, Node *&delNode) {
        if (!node) return nullptr;

        Node *retNode = node;
        if (key < retNode->key)
            retNode->lChild = remove(retNode->lChild, key, delNode);
        else if (key > retNode->key)
            retNode->rChild = remove(retNode->rChild, key, delNode);
        else {
            delNode = retNode;
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
                retNode->rChild = removeMin(retNode->rChild, successor);
                successor->lChild = retNode->lChild;
                successor->rChild = retNode->rChild;
                retNode->lChild = retNode->rChild = nullptr;
                retNode = successor;
            }
        }
        return retNode;
    }

    Node *copy(Node *s, Node *t) {
        if (!s) return nullptr;
        auto *node = new Node(s->key, s->value);
        node->lChild = copy(s->lChild, t->lChild);
        node->rChild = copy(s->rChild, t->rChild);
        return node;
    }

    int height(Node *node) const {
        if (!node) return 0;
        return 1 + std::max(height(node->lChild), height(node->rChild));
    }

public:
    BST() : m_root(nullptr), m_size(0) {}

    ~BST() { delete m_root; }

    BST(const BST &tree) {
        m_root = copy(tree.m_root, m_root);
        m_size = tree.m_size;
    }

    BST &operator=(const BST &tree) {
        if (&tree == this)
            return *this;

        delete m_root;
        m_size = tree.m_size;
        m_root = copy(tree.m_root, m_root);
    }

    int size() const { return m_size; }

    bool empty() const { return m_size > 0; }

    int height() const { return height(m_root); }

    void add(const K &key, V val) { m_root = add(m_root, key, val); }

    bool contains(const K &e) { return getNode(m_root, e) != nullptr; }

    V &remove(const K &key) {
        Node *node = nullptr;
        m_root = remove(m_root, key, node);

        if (node == nullptr)
            throw range_error("Key Error.");

        V ret = node->value;
        delete node;
        return ret;
    }

    V &get(const K &key) {
        auto node = getNode(m_root, key);
        if (node == nullptr)
            throw range_error("Key Error.");
        return node->value;
    }

    void preOrder(visitFunc visit) { preOrder(m_root, visit); }

    void inOrder(visitFunc visit) { inOrder(m_root, visit); }

    void postOrder(visitFunc visit) { postOrder(m_root, visit); }

    template<class K1, class V1>
    friend std::ostream &operator<<(std::ostream &os, const BST<K1, V1> &tree) {
        if (tree.empty())
            return os << std::endl;
        int level, h = tree.height();
        ListQueue<Node *> q;
        q.enqueue(tree.m_root);
        while (!q.empty() && h > 0) {
            level = q.size();
            h--;
            for (; level > 0; level--) {
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

#endif