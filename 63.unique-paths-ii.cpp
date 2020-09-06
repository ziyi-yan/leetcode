#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
  public:
    // a = isObstacle(i-1, j) ? 0 : dp[i-1][j]
    // b = isObstacle(i, j-1) ? 0 : dp[i][j-1]
    // dp[i][j] = isObstacle(i, j) ? 0 : a + b;
    //    dp[i][0] = 1, for i in [0, m)
    //                  if there is no obstacle between (0,0) to (i, 0)
    //    dp[0][j] = 1, for j in [0, n)
    //                  if there is no obstacle between (0,0) to (0, j)
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        if (obstacleGrid[0].empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        int val = 1;
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                val = 0;
            }
            dp[i][0] = val;
        }
        val = 1;
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) {
                val = 0;
            }
            dp[0][j] = val;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
