#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Increasing Subsequences
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return result;
    }

private:
    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            auto str = stringify(curr);
            if (curr.size() > 1 && dedup.find(str) == dedup.end())
            {
                result.push_back(curr);
                dedup.insert(str);
            }
            return;
        }

        // use nums[i]
        if (curr.empty() || curr[curr.size() - 1] <= nums[i])
        {
            curr.push_back(nums[i]);
            dfs(nums, i + 1);
            curr.pop_back();
        }

        // don't use nums[i]
        dfs(nums, i + 1);
    }
    string stringify(vector<int> xs)
    {
        string str;
        for (auto x : xs)
        {
            str.append(to_string(x));
            str.push_back(';');
        }
        return str;
    }
    vector<int> curr;
    vector<vector<int>> result;
    unordered_set<string> dedup;
};
// @lc code=end
