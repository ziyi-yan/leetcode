#include <string>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=753 lang=cpp
 *
 * [753] Cracking the Safe
 */

// @lc code=start
class Solution
{
public:
    string crackSafe(int n, int k)
    {
        this->k = k;
        string start(n - 1, '0'); // start with all '0's node
        dfs(start);
        return result + start;
    }

private:
    void dfs(string node)
    {
        for (auto i = 0; i < k; i++)
        {
            auto n = node + to_string(i);
            if (!visited.count(n))
            {
                visited.insert(n);
                dfs(n.substr(1));
                // NOTE: similiar problem 332.reconstruct-itinerary (check out here: https://github.com/ziyi-yan/leetcode/blob/9e1c5e9449f2254531c9df1767cbfdbf07adf097/332.reconstruct-itinerary.cpp#L44)
                // But they are different when backtracking. Problem 332 is storing nodes. Instead, this problem needs storing paths.
                result.push_back(i + '0');
            }
        }
    }
    unordered_set<string> visited;
    int k;
    string result;
};
// @lc code=end
int main() {}
