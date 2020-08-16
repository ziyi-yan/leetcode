#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution
{
    int max;
    unordered_map<int, int> map; // value -> count

public:
    // KEY HIDDEN CONDITINO:
    // 1. When you take a number, you should take all of it
    //    because it gives you the most of the points.
    // OPTIMAL SOLUTION:
    // avoid[i] = max(avoid[i-1], using[i-1])
    // using[i] =
    //     if (nums[i] - 1 == nums[i-1]):
    //         nums[i] * cnt[i] + avoid[i-1]
    //     else:
    //         nums[i] * cnt[i] + max(avoid[i-1], using[i-1])
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_set<int> uniq;
        for (auto n : nums)
        {
            if (map.find(n) == map.end())
            {
                map[n] = 1;
                uniq.insert(n);
            }
            else
                map[n] += 1;
        }

        dfs(0, uniq);

        return max;
    }

    void dfs(int prev, unordered_set<int> uniq)
    {
        for (auto n : uniq)
        {
            auto curr = prev + n;
            if (curr > max)
                max = curr;

            map[n] -= 1;
            auto new_uniq = uniq;
            new_uniq.erase(n - 1);
            new_uniq.erase(n + 1);
            if (map[n] == 0)
                new_uniq.erase(n);
            dfs(curr, new_uniq);
            map[n] += 1;
        }
    }
};
// @lc code=end
int main()
{
    vector<int> input = {3, 4, 2};
    Solution{}.deleteAndEarn(input);
}