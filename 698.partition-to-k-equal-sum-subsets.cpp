#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
    enum class State {
        UNINIT,
        TRUE,
        FALSE,
    };
    int target;
    bool dfs(vector<State> &memo, vector<int> &nums, int used, int remain) {
        if (memo[used] == State::UNINIT) {
            memo[used] = State::FALSE;
            int threshold = (remain - 1) % target + 1;
            for (int i = 0; i < nums.size(); i++) {
                if ((((used >> i) & 1) == 0) && nums[i] <= threshold) {
                    if (dfs(memo, nums, used | (1 << i), remain - nums[i])) {
                        memo[used] = State::TRUE;
                        break;
                    }
                }
            }
        }
        return memo[used] == State::TRUE;
    }

   public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        this->target = target;
        // Use a integer as a bitset for storing the state whether each
        // element are used.
        // 1 for true, -1 for faulse, 0 for uninitialized.
        vector<State> memo(1 << nums.size(), State::UNINIT);
        memo[(1 << nums.size()) - 1] = State::TRUE;
        return dfs(memo, nums, 0, sum);
    }
};
// @lc code=end
int main() {
    vector<int> input = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    auto result = Solution().canPartitionKSubsets(input, k);
}
