#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
    bool dfs(vector<int> &nums, int target, int idx, int curr) {
        if (idx == nums.size()) {
            return curr == target;
        }

        if (dfs(nums, target, idx + 1, curr + nums[idx])) {
            return true;
        }

        return dfs(nums, target, idx + 1, curr);
    }

  public:
    bool canPartition(vector<int> &nums) {
        auto sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }

        auto target = sum / 2;
        return dfs(nums, target, 0, 0);
    }
};
// @lc code=end
