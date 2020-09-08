#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
  public:
    // dp[n+1][target+1];
    // dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
    // dp[0][0] = true
    // dp[i][0] = true
    // dp[0][j] = false
    bool canPartition(vector<int> &nums) {
        auto sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }

        auto target = sum / 2;

        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int j = target; j - x >= 0; j--) {
                dp[j] = dp[j] || dp[j - x];
            }
        }
        return dp[target];
    }
};
// @lc code=end
int main() {
    vector<int> input = {1, 2, 5};
    auto result = Solution().canPartition(input);
}
