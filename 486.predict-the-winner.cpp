#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
    // search returns a integer as a score which is the score of player 1 minus
    // the score of player 2. In player 1's turn, it will try to maximize the
    // score. In player 2's turn, it will try to minimize the score.
    int search(vector<int> nums, int l, int r, bool is_p1) {
        if (l == r) {
            return is_p1 ? nums[l] : -nums[l];
        }
        if (is_p1) {
            auto a = nums[l] + search(nums, l + 1, r, !is_p1);
            auto b = nums[r] + search(nums, l, r - 1, !is_p1);
            return max(a, b);
        } else {
            auto a = -nums[l] + search(nums, l + 1, r, !is_p1);
            auto b = -nums[r] + search(nums, l, r - 1, !is_p1);
            return min(a, b);
        }
    }

  public:
    bool PredictTheWinner(vector<int> &nums) {
        return search(nums, 0, nums.size() - 1, true) >= 0;
    }
};
// @lc code=end
int main() {
    vector<int> input = {2, 4, 55, 6, 8};
    auto result = Solution().PredictTheWinner(input);
}
