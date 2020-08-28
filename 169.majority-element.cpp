#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Reference: Approach 6: Boyer-Moore Voting Algorithm in https://leetcode.com/problems/majority-element/solution/
        int major;
        int count = 0;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (count == 0)
            {
                major = nums[i];
                count++;
            }
            else if (nums[i] == major)
                count++;
            else
                count--;
        }
        return major;
    }
};
// @lc code=end
