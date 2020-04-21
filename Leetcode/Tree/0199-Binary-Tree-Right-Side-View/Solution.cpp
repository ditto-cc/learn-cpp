
/*
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <deque>
#include "../TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        deque<TreeNode*> q(1, root);
        while (!q.empty()) {
            int size = q.size();
            res.push_back(q[size-1]->val);
            for (int i = 0; i < size; i++) {
                TreeNode *node = q[i];
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            q.erase(q.begin(), q.begin()+size);
        }

        return res;
    }
};