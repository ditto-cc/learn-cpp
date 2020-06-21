
/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../TreeNode.h"
#include <algorithm>
using namespace std;

class Solution {
private:
    int res;
    int maxPath(TreeNode* root) {
        if (!root)
            return 0;
        int l = max(maxPath(root->left), 0);
        int r = max(maxPath(root->right), 0);

        int maxCur = l + r + root->val;
        if (maxCur > res)
            res = maxCur;

        return max(l, r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        maxPath(root);
        return res;
    }
};