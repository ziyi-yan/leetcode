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
        for (auto i = n - 1, j = 2 * n - 1; i >= 0; i--, j--)
        {
            nums[j] = (nums[i] << 10) | nums[j];
        }
        for (auto i = 0; i < n; i++)
        {
            nums[2 * i] = nums[n + i] >> 10;
            nums[2 * i + 1] = nums[n + i] & ((1 << 10) - 1);
        }

        return nums;
    }
};
// @lc code=end
int main()
{
    vector<int> input = {2, 5, 1, 3, 4, 7};
    int n = 3;
    auto result = Solution().shuffle(input, n);
}