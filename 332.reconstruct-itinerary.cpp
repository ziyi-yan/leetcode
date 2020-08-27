#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, vector<string>> m;
        for (auto t : tickets)
        {
            auto from = t[0], to = t[1];
            m[from].push_back(to);
        }
        size = tickets.size() + 1;
        result.push_back("JFK");
        dfs(m, 1);
        return result;
    }

private:
    bool dfs(unordered_map<string, vector<string>> &m, int curr)
    {
        if (curr == size)
            return true;

        auto from = result[result.size() - 1];
        sort(m[from].begin(), m[from].end(), [](const string &lhs, const string &rhs) { return lhs.compare(rhs); });
        for (auto to : m[from])
        {
            result.push_back(to);
            if (dfs(m, curr + 1))
                return true;
            result.pop_back();
        }
        return false;
    }
    vector<string> result;
    int size;
};
// @lc code=end
