#include <vector>
#include <string>
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
    int max_num_of_strs = 0;
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> zeros_and_ones;
        for (auto s : strs)
        {
            auto zeros = count_ch(s, '0');
            auto ones = count_ch(s, '1');
            zeros_and_ones.push_back(make_pair(zeros, ones));
        }

        dfs(zeros_and_ones, 0, 0, 0, 0, m, n);

        return max_num_of_strs;
    }

    void dfs(vector<pair<int, int>> &vec, int curr, int prev_count, int prev_zeros, int prev_ones, int m, int n)
    {
        if (prev_zeros <= m && prev_ones <= n && prev_count > max_num_of_strs)
            max_num_of_strs = prev_count;

        if (prev_zeros > m || prev_ones > n)
            return;
        if (curr == vec.size())
            return;

        dfs(vec, curr + 1, prev_count + 1, prev_zeros + vec[curr].first, prev_ones + vec[curr].second, m, n);
        dfs(vec, curr + 1, prev_count, prev_zeros, prev_ones, m, n);
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
