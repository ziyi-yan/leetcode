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
        unordered_map<int, int> count;
        for (auto n : nums)
        {
            count[n]++;
            if (count[n] > nums.size() / 2)
                return n;
        }
        return 0; // code may never run here.
    }
};
// @lc code=end
