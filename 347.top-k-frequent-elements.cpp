#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            count[x] += 1;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            min_heap;
        for (auto x : count) {
            if (min_heap.size() < k) {
                min_heap.emplace(make_pair(x.second, x.first));
            } else {
                min_heap.emplace(make_pair(x.second, x.first));
                min_heap.pop();
            }
        }
        vector<int> result;
        result.reserve(k);
        while (min_heap.size()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
// @lc code=end
int main() {
    vector<int> input = {1, 1, 1, 2, 2, 3};
    auto result = Solution().topKFrequent(input, 2);
}
