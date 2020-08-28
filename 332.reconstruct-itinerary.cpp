#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
// Standard DFS solution: https://leetcode-cn.com/problems/reconstruct-itinerary/solution/332-zhong-xin-an-pai-xing-cheng-hui-su-fa-shen-sou/
// NOTE: use (ordered) map from key to its count for lexical order iterating and mutating at same time.
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, map<string, int>> m;
        for (auto t : tickets)
        {
            auto from = t[0], to = t[1];
            m[from][to] += 1;
        }
        size = tickets.size() + 1;
        result.push_back("JFK");
        dfs(m);
        return result;
    }

private:
    bool dfs(unordered_map<string, map<string, int>> &m)
    {
        if (result.size() == size)
            return true;

        auto from = result[result.size() - 1];
        for (auto &to : m[from])
        {
            if (to.second)
            {
                to.second--;
                result.push_back(to.first);
                if (dfs(m))
                    return true;
                result.pop_back();
                to.second++;
            }
        }
        return false;
    }
    vector<string> result;
    int size;
};
// @lc code=end
int main()
{
    vector<vector<string>> input = {
        {"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}};
    auto result = Solution().findItinerary(input);
}
