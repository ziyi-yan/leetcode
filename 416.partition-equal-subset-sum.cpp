#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        auto sum = 0;
        for (auto x : nums) {
            sum += x;
        }

        auto curr = 0;
        for (auto i = 0; i < nums.size(); i++) {
            curr += nums[i];
            if (2 * curr >= sum) {
                return 2 * curr == sum;
            }
        }
        return false;
    }
};
// @lc code=end
