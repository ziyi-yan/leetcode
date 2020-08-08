#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            auto remain = target - nums[i];
            auto found = map.find(remain);
            if (found != map.end() && i < found->second)
            {
                result.push_back(i);
                result.push_back(found->second);
            }
        }
        return result;
    }
};
// @lc code=end
