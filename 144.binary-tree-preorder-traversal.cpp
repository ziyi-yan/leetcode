#include <stack>
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

        stack<TreeNode *> s;
        result.push_back(root->val);
        s.push(root->right);
        s.push(root->left);
        while (s.size()) {
            auto top = s.top();
            s.pop();
            if (top) {
                result.push_back(top->val);
                s.push(top->right);
                s.push(top->left);
            }
        }

        return result;
    }
};
// @lc code=end
