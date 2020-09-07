#include <cmath>
/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    struct Result {
        bool is_balanced;
        int height;
    };
    Result check(TreeNode *root) {
        if (!root) {
            return Result{.is_balanced = true, .height = 0};
        }

        auto l = check(root->left);
        if (!l.is_balanced) {
            return Result{.is_balanced = false};
        }
        auto r = check(root->right);
        if (!r.is_balanced) {
            return Result{.is_balanced = false};
        }
        auto diff =
            l.height > r.height ? l.height - r.height : r.height - l.height;
        if (diff > 1) {
            return Result{.is_balanced = false};
        }
        return Result{.is_balanced = true,
                      .height =
                          (l.height > r.height ? l.height : r.height) + 1};
    }

  public:
    bool isBalanced(TreeNode *root) {
        auto result = check(root);
        return result.is_balanced;
    }
};
// @lc code=end
