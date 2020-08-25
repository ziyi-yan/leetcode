#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> result;
        for (auto i = 0; i < n; i++)
        {
            result.push_back(nums[i]);
            result.push_back(nums[n + i]);
        }
        return result;
    }
};
// @lc code=end
