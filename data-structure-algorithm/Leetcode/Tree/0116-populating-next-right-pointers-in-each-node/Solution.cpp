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
        Node *nextFirst = nullptr, *cur = nullptr;
        for (Node *p = root; p && p->left;) {
            if (!cur) {
                cur = nextFirst = p->left;
            } else {
                cur->next = p->left;
                cur = cur->next;
            }

            cur->next = p->right;

            if (p->next) {
                p = p->next;
            } else {
                p = nextFirst;
                nextFirst = cur = nullptr;
            }
        }

        return root;
    }

};