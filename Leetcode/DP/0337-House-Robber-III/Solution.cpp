
/*
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <algorithm>
#include "../../Tree/TreeNode.h"
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
private:
    int *robSolution(TreeNode *root) {
        int *res = new int[2];
        if (!root) {
            res[0] = res[1] = 0;
            return res;
        }
        int *left = robSolution(root->left);
        int *right = robSolution(root->right);
        // 抢这个节点，所以不能抢孩子节点
        res[0] = root->val + left[1] + right[1];
        // 不抢这个节点，可以抢也可以不抢孩子节点，所以选最优
        res[1] = max(left[0], left[1]) + max(right[0], right[1]);
        delete []left;
        delete []right;
        return res;
    }
public:
    int rob(TreeNode* root) {
        int *r = robSolution(root);
        int res = max(r[0], r[1]);
        delete []r;
        return res;
    }
};