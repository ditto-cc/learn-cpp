
#ifndef _AVL_H
#define _AVL_H

#include <iostream>
#include <functional>
#include <queue>

using std::range_error;
using std::max;

template<class K, class V>
class AVL {
private:

    class Node {
    public:
        K key;
        V value;
        int height;
        Node *lChild, *rChild;

        Node(K k, V v, int height,
             Node *l = nullptr, Node *r = nullptr) :
                key(k), value(v), height(height),
                lChild(l), rChild(r) {}

        ~Node() { delete lChild, rChild; }
    };

    Node *m_root;
    int m_size;
    typedef std::function<void(const K &key, V &value)> visitFunc;

    void preOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        visit(root->key, root->value);
        preOrder(root->lChild, visit);
        preOrder(root->rChild, visit);
    }

    void inOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        inOrder(root->lChild, visit);
        visit(root->key, root->value);
        inOrder(root->rChild, visit);
    }

    void postOrder(Node *root, visitFunc visit) {
        if (root == nullptr)
            return;
        postOrder(root->lChild, visit);
        postOrder(root->rChild, visit);
        visit(root->key, root->value);
    }

    int getBalanceFactor(Node *node) const {
        if (!node) return 0;
        return height(node->lChild) - height(node->rChild);
    }

    Node *leftRotate(Node *node) {
        if (!node) return nullptr;
        Node *rc = node->rChild;
        node->rChild = rc->lChild;
        rc->lChild = node;
        node->height = 1 + max(height(node->lChild), height(node->rChild));
        rc->height = 1 + max(height(rc->lChild), height(rc->rChild));
        return rc;
    }

    Node *rightRotate(Node *node) {
        if (!node) return nullptr;
        Node *lc = node->lChild;
        node->lChild = lc->rChild;
        lc->rChild = node;
        node->height = 1 + max(height(node->lChild), height(node->rChild));
        lc->height = 1 + max(height(lc->lChild), height(lc->rChild));
        return lc;
    }

    Node *rotate(Node *node) {
        if (!node) return nullptr;

        Node *retNode = node;
        retNode->height = 1 + max(height(retNode->lChild), height(retNode->rChild));

        int balanceFactor = getBalanceFactor(retNode);
        if (balanceFactor > -2 && balanceFactor < 2) return retNode;

        int lb = getBalanceFactor(node->lChild);
        int rb = getBalanceFactor(node->rChild);
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

    Node *add(Node *node, const K &key, const V &value) {
        if (node == nullptr) {
            m_size++;
            return new Node(key, value, 1);
        }
        if (node->key < key)
            node->rChild = add(node->rChild, key, value);
        else if (node->key > key)
            node->lChild = add(node->lChild, key, value);
        else
            node->value = value;
        return rotate(node);
    }

    Node *getNode(Node *node, const K &key) const {
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
        return rotate(node);
    }

    Node *removeMax(Node *node, Node *&maxNode) {
        if (node == nullptr)
            return nullptr;
        if (node->rChild == nullptr) {
            Node *ret = node->lChild;
            node->lChild = nullptr;
            maxNode = node;
            m_size--;
            return ret;
        }
        node->rChild = removeMax(node->rChild, maxNode);
        return rotate(node);
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
        return rotate(retNode);
    }

    Node *copy(Node *s, Node *t) {
        if (!s) return nullptr;
        auto *node = new Node(s->key, s->value, s->height);
        node->lChild = copy(s->lChild, t->lChild);
        node->rChild = copy(s->rChild, t->rChild);
        return node;
    }

    int height(Node *node) const {
        if (!node) return 0;
        return node->height;
    }

public:
    AVL() : m_root(nullptr), m_size(0) {}

    AVL(const AVL &tree) {
        m_root = copy(tree.m_root, m_root);
        m_size = tree.m_size;
    }

    AVL &operator=(const AVL &tree) {
        if (&tree == this)
            return *this;

        delete m_root;
        m_size = tree.m_size;
        m_root = copy(tree.m_root, m_root);
    }

    ~AVL() { delete m_root; }

    int size() const { return m_size; }

    bool empty() const { return m_size == 0; }

    int height() const { return height(m_root); }

    void add(const K &key, const V &value) { m_root = add(m_root, key, value); }

    bool contains(const K &key) const { return getNode(m_root, key) != nullptr; }

    V &get(const K &key) const {
        Node *node = getNode(m_root, key);
        if (!node)
            throw range_error("Key Error");
        return node->value;
    }

    V &remove(const K &key) {
        Node *node = nullptr;
        m_root = remove(m_root, key, node);
        if (!node)
            throw range_error("Key Error");
        V &ret = node->value;
        delete node;
        return ret;
    }

    void preOrder(visitFunc visit) { preOrder(m_root, visit); }

    void inOrder(visitFunc visit) { inOrder(m_root, visit); }

    void postOrder(visitFunc visit) { postOrder(m_root, visit); }

    friend std::ostream &operator<<(std::ostream &os, const AVL<K, V> &tree) {
        if (tree.empty())
            return os << "NULL" << std::endl;
        int level, h = tree.height();
        std::queue<Node *> q;
        q.push(tree.m_root);
        while (!q.empty() && h > 0) {
            level = q.size();
            h--;
            for (; level > 0; level--) {
                Node *front = q.front();
                q.pop();
                if (front == nullptr) {
                    os << "NULL ";
                    q.push(nullptr);
                    q.push(nullptr);
                } else {
                    os << "(" << front->key << ", " << front->value << ") ";
                    q.push(front->lChild);
                    q.push(front->rChild);
                }
            }
            os << std::endl;
        }
        return os;
    }
};

#endif