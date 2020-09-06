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
    int countChange(vector<int> &coins, int idx, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (idx == coins.size()) {
            return -1;
        }

        int n = amount / coins[idx];
        int min_num_coins = numeric_limits<int>::max();
        for (auto i = 0; i <= n; i++) {
            auto count = countChange(coins, idx + 1, amount - i * coins[idx]);
            if (count != -1) {
                min_num_coins = min(min_num_coins, count + i);
            }
        }
        if (min_num_coins == numeric_limits<int>::max()) {
            return -1;
        } else {
            return min_num_coins;
        }
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (coins.empty())
            return -1;

        return countChange(coins, 0, amount);
    }
};
// @lc code=end

int main() {
    // auto input = vector<int>{1, 2, 5};
    // auto result = Solution().coinChange(input, 11);
    auto input = vector<int>{186, 419, 83, 408};
    auto result = Solution().coinChange(input, 6249);
}
