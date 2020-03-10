#include <cstdlib>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (nullptr == root)
            return nullptr;

        Node *l, *r;
        Node *cur = nullptr, *nextFirst = nullptr;
        for (Node *p = root; p != nullptr; p = p->next) {
            l = p->left;
            r = p->right;

            if (l) {
                if (cur) {
                    cur->next = l;
                } else {
                    nextFirst = l;
                }
                cur = l;
            }

            if (r) {
                if (cur) {
                    cur->next = r;
                } else {
                    nextFirst = r;
                }
                cur = r;
            }

            if (p->next == nullptr) {
                p = nextFirst;
                nextFirst = nullptr;
            }
        }

        return root;
    }

};