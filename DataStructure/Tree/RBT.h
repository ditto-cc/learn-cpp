
#ifndef _RBT_H
#define _RBT_H
#include <iostream>
#include <functional>
#include <queue>

using std::range_error;

template<class K, class V>
class RBT {
private:
    static const bool RED = true;
    static const bool BLACK = true;

    class Node {
    public:
        K key;
        V value;
        Node *lChild, *rChild;
        bool color;

        explicit Node(K key, V val,
                      Node *l = nullptr, Node *r = nullptr):
                key(key), value(val),
                lChild(l), rChild(r), color(RED) {}

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

    Node *leftRotate(Node *node) {
        Node *rc = node->rChild;
        node->rChild = rc->lChild;
        rc->lChild = node;

        rc->color = node->color;
        node->color = RED;
        return rc;
    }

    void flipColor(Node *node) {
        node->color = RED;
        node->lChild->color = node->rChild->color = BLACK;
    }

    Node *rightRotate(Node *node) {
        Node *lc = node->lChild;
        node->lChild = lc->rChild;
        lc->rChild = node;

        lc->color = node->color;
        node->color = RED;
        return lc;
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

        if (isRed(node->rChild) && !isRed(node->lChild))
            node = leftRotate(node);

        if (isRed(node->lChild) && isRed(node->lChild->lChild))
            node = rightRotate(node);

        if (isRed(node->lChild) && isRed(node->rChild))
            flipColor(node);
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

    bool isRed(Node *node) {
        if (!node) return false;
        return node->color;
    }

public:
    RBT() : m_root(nullptr), m_size(0) {}

    ~RBT() { delete m_root; }

    RBT(const RBT &tree) {
        m_root = copy(tree.m_root, m_root);
        m_size = tree.m_size;
    }

    RBT &operator=(const RBT &tree) {
        if (&tree == this)
            return *this;

        delete m_root;
        m_size = tree.m_size;
        m_root = copy(tree.m_root, m_root);
    }

    int size() const { return m_size; }

    bool empty() const { return m_size == 0; }

    int height() const { return height(m_root); }

    void add(const K &key, V val) {
        m_root = add(m_root, key, val);
        m_root->color = BLACK;
    }

    bool contains(const K &e) { return getNode(m_root, e) != nullptr; }

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
    friend std::ostream &operator<<(std::ostream &os, const RBT<K1, V1> &tree) {
        if (tree.empty())
            return os << std::endl;
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