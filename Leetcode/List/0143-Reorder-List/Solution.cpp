/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "../ListNode.h"


class Solution {
public:
    void reorderList(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;

        auto pre = dummy, p = head, q = head;
        while (q) {
            pre = p;
            p = p->next;
            q = q->next;
            if (q)
                q = q->next;
        }

        pre->next = nullptr;
        q = head;

        pre = nullptr;
        while (p) {
            auto next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }


        while (q) {
            p = pre->next;
            auto qn = q->next;

            q->next = pre;
            q = pre;
            pre = p;
            q->next = qn;
            q = qn;
        }
    }
};