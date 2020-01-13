
#ifndef _BST_H
#define _BST_H


template <typename T>
class BST {
public:
    class BTNode {
    public:
        T data;
        BTNode *lchild, *rchild;

        BTNode(T e, BTNode *l = nullptr, BTNode *r = nullptr) : data(e), lchild(l), rchild(r) {}
        ~BTNode() { delete lchild, rchild; }
    };
private:
    BTNode *m_root;

    void __preOrder(BTNode *root, void (*visit)(const T &e));
    void __inOrder(BTNode *root, void (*visit)(const T &e));
    void __postOrder(BTNode *root, void (*visit)(const T &e));

    BTNode *__add(BTNode *node, const T &e) {
        if (node == nullptr)
            return new BTNode(e);
        if (node->data < e)
            node->rchild = __add(node->rchild, e);
        else if (node->data > e)
            node->lchild = __add(node->lchild, e);
        return node;
    }

    BTNode *__getNode(BTNode *node, const T &e) {
        if (node == nullptr)
            return nullptr;
        if (node->data < e)
            return __getNode(node->rchild, e);
        else if (node->data > e)
            return __getNode(node->lchild, e);
        return node;
    }

    BTNode *__getSuccession(BTNode *node) {
        if (node == nullptr || node->rchild == nullptr)
            return nullptr;
        BTNode *p = node->rchild;

        while (p->lchild)
            p = p->lchild;

        return p;
    }

    BTNode *__removeMin(BTNode *node) {
        if (node == nullptr)
            return nullptr;
        if (node->lchild == nullptr) {
            BTNode *ret = node->rchild;
            node->rchild = nullptr;
            delete node;
            return ret;
        }
        node->lchild = __removeMin(node->lchild);
        return node;
    }

    BTNode *__remove(BTNode *node, const T &e) {
        
    }

public:
    BST() : m_root(nullptr) {}
    ~BST() { delete m_root; }

    BST(const BST &tree);
    BST &operator=(const BST &tree);

    void add(const T &e) { m_root = __add(m_root, e); }
    bool contains(const T &e) { return __getNode(m_root, e) != nullptr; }
    bool remove(const T &e);

    void preOrder(void (*visit)(const T &e)) { __preOrder(visit); }
    void inOrder(void (*visit)(const T &e)) { __inOrder(visit); }
    void postOrder(void (*visit)(const T &e)) { __postOrder(visit); }
};

template<typename T>
void BST<T>::__preOrder(BTNode *root, void (*visit)(const T &e)) {
    if (root == nullptr)
        return;
    visit(root->data);
    __preOrder(root->lchild, visit);
    __preOrder(root->rchild, visit);
}

template<typename T>
void BST<T>::__inOrder(BTNode *root, void (*visit)(const T &)) {
    if (root == nullptr)
        return;
    __preOrder(root->lchild, visit);
    visit(root->data);
    __preOrder(root->rchild, visit);
}

template<typename T>
void BST<T>::__postOrder(BTNode *root, void (*visit)(const T &)) {
    if (root == nullptr)
        return;
    __preOrder(root->lchild, visit);
    __preOrder(root->rchild, visit);
    visit(root->data);
}




#endif