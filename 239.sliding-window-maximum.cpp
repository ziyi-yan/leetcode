#include <queue>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
const int HEAP_SIZE = 3;
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

        priority_queue<int, vector<int>, greater<int>> min_heap;
        priority_queue<int> max_heap;
        vector<int> buffer;
        buffer.reserve(3);
        for (int i = 0; i < k; i++) {
            min_heap.push(nums[i]);
            if (min_heap.size() > 3) {
                min_heap.pop();
            }
        }
        while (min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        result.push_back(max_heap.top());
        for (int i = k; i < nums.size(); i++) {
            // remove nums[i-k]
            bool deleted = false;
            while (max_heap.size()) {
                if (!deleted && max_heap.top() == nums[i - k]) {
                    deleted = true;
                } else {
                    buffer.push_back(max_heap.top());
                }
                max_heap.pop();
            }
            for (auto x : buffer) {
                max_heap.push(x);
            }
            buffer.resize(0);
            // add nums[i]
            max_heap.push(nums[i]);

            result.push_back(max_heap.top());
        }

        return result;
    }
};
// @lc code=end
