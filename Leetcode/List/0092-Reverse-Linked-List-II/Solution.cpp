/**
 * 
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/reverse-linked-list-ii
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || !head->next) {
            return head;
        }

        int k = n - m + 1;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p = dummy;
        for (; m > 1; m--, p = p->next);

        ListNode *pre = p, *cur = p->next, *next;
        for (; k > 0; k--) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        p->next->next = cur;
        p->next = pre;

        return dummy->next;
    }
};