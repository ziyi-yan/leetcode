#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode *> s;
        while (root || s.size()) {
            while (root) {
                s.push(root);
                root = root->left;
            }

            auto top = s.top();
            s.pop();
            if (top) {
                result.push_back(top->val);
                root = top->right;
            }
        }
        return result;
    }
};
// @lc code=end
