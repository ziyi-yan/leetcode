#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
    bool search(vector<int> nums, int l, int r, int p1, int p2, bool is_p1) {
        if (l > r) {
            return p1 >= p2;
        }
        if (is_p1) {
            if (search(nums, l + 1, r, p1 + nums[l], p2, !is_p1)) {
                return true;
            }
            if (search(nums, l, r - 1, p1 + nums[r], p2, !is_p1)) {
                return true;
            }
        } else {
            if (nums[l] >= nums[r]) {
                if (search(nums, l + 1, r, p1, p2 + nums[l], !is_p1)) {
                    return true;
                }
            } else {
                if (search(nums, l, r - 1, p1, p2 + nums[r], !is_p1)) {
                    return true;
                }
            }
        }
        return false;
    }

  public:
    bool PredictTheWinner(vector<int> &nums) {
        return search(nums, 0, nums.size() - 1, 0, 0, true);
    }
};
// @lc code=end
int main() {
    vector<int> input = {2, 4, 55, 6, 8};
    auto result = Solution().PredictTheWinner(input);
}
