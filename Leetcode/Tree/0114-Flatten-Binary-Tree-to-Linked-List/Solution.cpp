/**
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 * The flattened tree should look like:
 * 
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
#include "TreeNode.h"
#include <vector>
using namespace std;

class Solution {

public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode *pre = NULL, *p = root;
        vector<TreeNode*> s(1, root);
        while (!s.empty()) {
            TreeNode *top = s[s.size()-1];
            s.pop_back();
            if (pre) {
                pre->left = NULL;
                pre->right = top;
            }
            if (top->right) s.push_back(top->right);
            if (top->left) s.push_back(top->left);
            pre = top;
        }
    }
};