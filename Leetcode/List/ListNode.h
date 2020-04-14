#ifndef LEETCODE_LISTNODE_
#define LEETCODE_LISTNODE_

#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* convertToList(std::vector<int> arr) {
    if (arr.empty()) {
        return nullptr;
    }

    auto head = new ListNode(arr[0]);
    auto p = head;
    for (int i = 1; i < arr.size(); i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return head;
}

#endif
