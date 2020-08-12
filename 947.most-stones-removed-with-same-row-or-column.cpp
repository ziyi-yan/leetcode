#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution
{
public:
    unordered_set<int> visited;

    int removeStones(vector<vector<int>> &stones)
    {
        // sub-optimal solution:
        // construct a graph: adjancent matrix,
        // and BFS to count the number of connected graphs

        // optimal solution:
        // it's a problem about graph
        // union find x with y
        // count the total connected graphs

        vector<vector<int>> graph(stones.size());

        unordered_map<int, int> x_map;
        unordered_map<int, int> y_map;

        for (auto i = 0; i < stones.size(); i++)
        {
            auto stone = stones[i];
            int x = stone[0];
            int y = stone[1];

            if (x_map.find(x) == x_map.end())
                x_map[x] = i;
            else
            {
                graph[x_map[x]].push_back(i);
                graph[i].push_back(x_map[x]);
            }

            if (y_map.find(y) == y_map.end())
                y_map[y] = i;
            else
            {
                graph[y_map[y]].push_back(i);
                graph[i].push_back(y_map[y]);
            }
        }

        int count = 0;
        for (auto i = 0; i < stones.size(); i++)
        {
            if (visited.find(i) == visited.end())
            {
                count += 1;
                dfs(graph, i);
            }
        }

        return stones.size() - count;
    }

    void dfs(vector<vector<int>> &graph, int node)
    {
        if (visited.find(node) != visited.end())
            return;

        visited.insert(node);

        auto neighbors = graph[node];
        for (auto neighbor : neighbors)
        {
            dfs(graph, neighbor);
        }
    }
};
// @lc code=end

int main()
{
    vector<vector<int>> stones = {{0, 1}, {1, 0}, {1, 1}};

    Solution().removeStones(stones);
}