#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp[i][j][k] means the maximum number of strings we can get from first i elements
        // with limited j number of 0s and k number of 1s.
        // dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-num_of_zeros(strs[i])][k-num_of_ones[strs[i]]]])
        // we can decrease the space complexity from i*j*k to j*k.
        // int dp[m + 1][n + 1];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto j = 0; j < m + 1; j++)
            for (auto k = 0; k < n + 1; k++)
                dp[j][k] = 0;

        for (auto s : strs)
        {
            auto zeros = count_ch(s, '0');
            auto ones = count_ch(s, '1');
            for (auto j = m; j >= 0; j--)
                for (auto k = n; k >= 0; k--)
                    if (j >= zeros && k >= ones)
                        dp[j][k] = max(dp[j][k], dp[j - zeros][k - ones] + 1);
        }

        return dp[m][n];
    }

    int count_ch(string s, char target)
    {
        int count = 0;
        for (auto ch : s)
        {
            if (ch == target)
                count += 1;
        }
        return count;
    }
};
// @lc code=end
int main()
{
    // ["10","0001","111001","1","0"]
    // 5
    // 3
    auto strs = vector<string>{"10", "0001", "111001", "1", "0"};
    Solution{}.findMaxForm(strs, 5, 3);
}