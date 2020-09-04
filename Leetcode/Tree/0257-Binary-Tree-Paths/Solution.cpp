/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
#include <string>
#include <vector>
#include "../TreeNode.h"

using namespace std;

class Solution {
private:
    void dfs(TreeNode *node, vector<string> &paths, vector<string> &path) {
        path.push_back(std::to_string(node->val));
        if (!node->left && !node->right) {
            string p = path[0];
            for (int i = 1, size = path.size(); i < size; i++)
                p.append("->" + path[i]);
            paths.push_back(p);
        } else {
            if (node->left)
                dfs(node->left, paths, path);
            if (node->right)
                dfs(node->right, paths, path);
        }
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root)
            return paths;
        vector<string> path;
        dfs(root, paths, path);
        return paths;
    }
};