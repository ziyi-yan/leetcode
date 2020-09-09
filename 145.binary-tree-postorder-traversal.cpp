#include <stack>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> nodes;
        if (!root) return nodes;

        stack<TreeNode *> s;
        while (root || s.size()) {
            while (root) {
                if (root->right) s.push(root->right);
                s.push(root);
                root = root->left;
            }
            auto top = s.top();
            s.pop();
            if (s.size() && top->right == s.top()) {
                root = s.top();
                s.pop();
                s.push(top);
            } else {
                nodes.push_back(top->val);
            }
        }
        return nodes;
    }
};
// @lc code=end
