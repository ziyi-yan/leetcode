#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
    int cnt = -1;
    bool dfs(vector<int> &coins, int s, int amount, int cnt) {
        if (s == coins.size()) {
            if (amount == 0) {
                this->cnt = cnt;
                return true;
            } else {
                return false;
            }
        }

        int n = amount / coins[s];
        for (int i = n; i >= 0; i--) {
            if (dfs(coins, s + 1, amount - i * coins[s], cnt + i)) {
                return true;
            }
        }
        return false;
    }

  public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return -1;
        if (coins.empty())
            return -1;

        sort(coins.begin(), coins.end(), greater<int>());

        dfs(coins, 0, amount, 0);

        return cnt;
    }
};
// @lc code=end

int main() {
    auto input = vector<int>{2};
    auto result = Solution().coinChange(input, 3);
}
