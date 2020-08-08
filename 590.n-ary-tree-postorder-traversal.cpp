/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

#include <vector>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> result{};
        if (root == nullptr)
        {
            return result;
        }

        for (Node *child : root->children)
        {
            auto child_postorder = postorder(child);
            result.insert(result.end(), child_postorder.begin(), child_postorder.end());
        }
        result.push_back(root->val);

        return result;
    }
};
// @lc code=end
