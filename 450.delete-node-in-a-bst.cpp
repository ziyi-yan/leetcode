/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (!root) {
            return root;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // Delete the root node
        if (!root->left) {
            return root->right;
        }
        if (!root->right) {
            return root->left;
        }
        // Delete the largest node in root->left subtree and put its value to
        // the root node.
        auto curr = root->left;
        auto parent = &root->left;
        while (curr->right) {
            parent = &curr->right;
            curr = curr->right;
        }
        root->val = curr->val;
        *parent = curr->left;
        return root;
    }
};
// @lc code=end
