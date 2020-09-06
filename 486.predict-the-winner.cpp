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
    int search(vector<int> nums, int s, int e, int turn) {
        if (s == e) {
            return turn * nums[s];
        }
        auto a = turn * nums[s] + search(nums, s + 1, e, -turn);
        auto b = turn * nums[e] + search(nums, s, e - 1, -turn);
        return turn * max(turn * a, turn * b);
    }

  public:
    bool PredictTheWinner(vector<int> &nums) {
        return search(nums, 0, nums.size() - 1, 1) >= 0;
    }
};
// @lc code=end
int main() {
    vector<int> input = {2, 4, 55, 6, 8};
    auto result = Solution().PredictTheWinner(input);
}
