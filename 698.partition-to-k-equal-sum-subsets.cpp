#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
    bool dfs(vector<int> &group, int i, vector<int> &nums, int target) {
        if (i == nums.size()) {
            // for (auto x : group) {
            //     if (x != target) return false;
            // }
            // NOTE: we don't need to check the sum because the condition 1)
            // `target = sum / k`, and 2) `group[i] <= target` can ensure that
            // if each element is placed on a group, the sum of each group must
            // be target.
            return true;
        }
        for (int j = 0; j < group.size(); j++) {
            if (group[j] + nums[i] <= target) {
                group[j] += nums[i];
                if (dfs(group, i + 1, nums, target)) return true;
                group[j] -= nums[i];
            }
        }
        return false;
    }

   public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        vector<int> group(k, 0);
        return dfs(group, 0, nums, target);
    }
};
// @lc code=end
int main() {
    vector<int> input = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    auto result = Solution().canPartitionKSubsets(input, k);
}
