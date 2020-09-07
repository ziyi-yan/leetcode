#include <algorithm>
#include <functional>
#include <limits>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
  public:
    // dp[i] = min_{j=0...n-1}{dp[i - coins[j]]} + 1
    // dp[0] = 0
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        int max_val = amount + 1;
        vector<int> dp(amount + 1, max_val);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == max_val ? -1 : dp[amount];
    }
};
// @lc code=end

int main() {
    // auto input = vector<int>{1, 2, 5};
    // auto result = Solution().coinChange(input, 11);
    auto input = vector<int>{186, 419, 83, 408};
    auto result = Solution().coinChange(input, 6249);
}
