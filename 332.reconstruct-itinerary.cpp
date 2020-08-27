#include <vector>
#include <string>
#include <queue>
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
        for (auto t : tickets)
        {
            auto from = t[0], to = t[1];
            m[from].push(to);
        }

        dfs("JFK");

        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(const string &curr)
    {
        while (m[curr].size())
        {
            auto next = m[curr].top();
            m[curr].pop(); // delete the path when forwarding to next node
            dfs(move(next));
        }
        // Add node to result when all its path is visited.
        // So, the node with odd degree will be added first.
        // And it will put all nodes in a reverse order in path.
        // Reference: https://leetcode-cn.com/problems/reconstruct-itinerary/solution/javadfsjie-fa-by-pwrliang/
        result.push_back(curr);
    }
    vector<string> result;
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;
};
// @lc code=end
