/**
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <algorithm>
#include <vector>
#include "../ListNode.h"

using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<ListNode *> s1, s2;
        for (auto p = l1; p; p = p->next) s1.push_back(p);
        for (auto p = l2; p; p = p->next) s2.push_back(p);

        int carry = 0;
        int i = s1.size() - 1, j = s2.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--) {
            s1[i]->val += s2[j]->val + carry;
            carry = s1[i]->val / 10;
            s1[i]->val %= 10;
        }

        ListNode *res;
        if (j >= 0) {
            s2[j]->next = l1;
            for (; carry > 0 && j >= 0; j--) {
                s2[j]->val += carry;
                carry = s2[j]->val / 10;
                s2[j]->val %= 10;
            }
            res = l2;
        } else {
            for (; carry > 0 && i >= 0; i--) {
                s1[i]->val += carry;
                carry = s1[i]->val / 10;
                s1[i]->val %= 10;
            }
            res = l1;
        }

        if (carry == 0) return res;

        auto *newHead = new ListNode(carry);
        newHead->next = res;
        return newHead;
    }
};