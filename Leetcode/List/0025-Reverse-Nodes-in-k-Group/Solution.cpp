/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-k-group
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

#include "../ListNode.h"

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p, *q;
        for (p = dummy; p->next; ) {
            int i;
            for (i = 0, q = p->next; i < k && q; q = q->next, i++);
            if (i < k) break;

            ListNode *pre = p, *cur = p->next;
            for (i = 0; i < k; i++) {
                ListNode *next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }

            ListNode *tail = p->next;
            tail->next = cur;
            p->next = pre;
            p = tail;
        };

        return dummy->next;
    }
};
