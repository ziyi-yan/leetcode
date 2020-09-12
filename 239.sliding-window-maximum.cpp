#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty()) return result;
        if (k == 1) return nums;
        if (k == 2) {
            for (int i = 0; i < nums.size() - 1; i++) {
                result.push_back(max(nums[i], nums[i + 1]));
            }
            return result;
        }

        deque<int> queue;
        // NOTE: we don't need to retain the smaller value before the maximun
        // one, so we pop all the smaller values when a larger one appears but
        // we append smaller ones when there is a larger one already in the
        // queue.
        for (int i = 0; i < k; i++) {
            while (queue.size() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }
            queue.push_back(i);
        }
        result.push_back(nums[queue.front()]);
        for (int i = k; i < nums.size(); i++) {
            if (queue.front() <= i - k) {
                queue.pop_front();
            }
            while (queue.size() && nums[queue.back()] < nums[i]) {
                queue.pop_back();
            }
            queue.push_back(i);
            result.push_back(nums[queue.front()]);
        }
        return result;
    }
};
// @lc code=end
