#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
    // dp[s][e] has the maximum score for the player who picks first in range
    // [s, e] in nums.
    //
    // dp[s][e] = max(nums[s] - dp[s+1][e], nums[e] - dp[s][e-1])
  public:
    bool PredictTheWinner(vector<int> &nums) {
        auto n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int s = n - 1; s >= 0; s--) {
            for (int e = s; e < n; e++) {
                if (s == e) {
                    dp[s][e] = nums[s];
                } else {
                    dp[s][e] =
                        max(nums[s] - dp[s + 1][e], nums[e] - dp[s][e - 1]);
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end
int main() {
    // vector<int> input = {2, 4, 55, 6, 8};
    vector<int> input = {1, 5, 2};
    auto result = Solution().PredictTheWinner(input);
}
