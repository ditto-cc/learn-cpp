//
// Created by cheng on 2020/9/25.
//

/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder =[9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
#include <vector>

using namespace std;


class Solution {
private:
    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int il, int ir, int &pj) {
        if (il > ir || pj < 0)
            return nullptr;

        int i = il;
        for (; i <= ir; i++) {
            if (inorder.at(i) == postorder.at(pj))
                break;
        }

        if (i == ir + 1)
            return nullptr;

        auto *node = new TreeNode(inorder.at(i));
        pj--;
        node->right = build(inorder, postorder, i + 1, ir, pj);
        node->left = build(inorder, postorder, il, i - 1, pj);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int pj = postorder.size() - 1;
        TreeNode *root = build(inorder, postorder, 0, pj, pj);
        return root;
    }
};