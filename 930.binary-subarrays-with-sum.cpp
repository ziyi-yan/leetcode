#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        auto count = 0;
        unordered_map<int, int> prefix_sum_count = {{0, 1}};
        auto curr = 0;
        for (auto i : A)
        {
            curr += i;
            count += prefix_sum_count[curr - S];
            prefix_sum_count[curr]++;
        }
        return count;
    }
};
// @lc code=end
