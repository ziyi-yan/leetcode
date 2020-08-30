#include <vector>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int total_max = 0;
        int negative_max = 0;
        int positive_max = 0;
        for (auto i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                positive_max += 1;
                if (negative_max > 0)
                    negative_max += 1;
            }
            else if (nums[i] < 0)
            {
                int old_nega_max = negative_max, old_posi_max = positive_max;
                negative_max = old_posi_max + 1;
                positive_max = old_nega_max > 0 ? old_nega_max + 1 : 0;
            }
            else
            {
                negative_max = 0;
                positive_max = 0;
            }

            if (positive_max > total_max)
                total_max = positive_max;
        }
        return total_max;
    }
};
// @lc code=end
int main()
{
    vector<int> input = {0, 1, -2, -3, -4};
    auto result = Solution().getMaxLen(input);
}
