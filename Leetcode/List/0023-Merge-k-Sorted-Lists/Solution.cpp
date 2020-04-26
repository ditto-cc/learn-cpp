
/*
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "../ListNode.h"
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool cmp(ListNode *a, ListNode *b) {
    if (!b)
        return true;
    if (!a)
        return false;

    return a->val <= b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        make_heap(lists.begin(), lists.end(), cmp);

        auto dummy = new ListNode(0);
        auto p = dummy;
        while (!lists.empty() && lists[0]) {
            p->next = lists[0];
            p = p->next;
            pop_heap(lists.begin(), lists.end(), cmp);
            if (lists[n-1]) {
                lists[n-1] = lists[n-1]->next;
            }
            push_heap(lists.begin(), lists.end(), cmp);
        }
        return dummy->next;
    }
};
