#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
 */
class Solution {
   public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) return result;

        result.push_back(root->val);

        auto l = preorderTraversal(root->left);
        result.insert(result.end(), l.begin(), l.end());

        auto r = preorderTraversal(root->right);
        result.insert(result.end(), r.begin(), r.end());

        return result;
    }
};
// @lc code=end
