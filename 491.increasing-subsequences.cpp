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
            if (curr.size() > 1)
                result.push_back(curr);
            return;
        }

        // use nums[i]
        if (curr.empty() || curr[curr.size() - 1] <= nums[i])
        {
            curr.push_back(nums[i]);
            dfs(nums, i + 1);
            curr.pop_back();
        }

        // For de-duplicate reason, if curr value is equal to previous one,
        // don't search for not-using-nums[i] case because it will be covered when
        // previous ones are in not-using cases.
        //
        // Example:
        // Input: [4, 6, 7, 7, 7, 8, 9]
        //
        // dfs(4,6,7,7,7...)
        //
        // dfs(4,6,X,7,7...)
        // dfs(4,6,7,7,X...) PRUNED CASE
        //
        // dfs(4,6,7,X,X...) PRUNED CASE
        // dfs(4,6,X,7,X...) PRUNED CASE
        // dfs(4,6,X,X,7...)
        if (!curr.empty() && nums[i] == curr[curr.size() - 1])
            return;

        // don't use nums[i]
        dfs(nums, i + 1);
    }
    vector<int> curr;
    vector<vector<int>> result;
};
// @lc code=end
