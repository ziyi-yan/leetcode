#include <algorithm>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution
{

public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> copied = heights;

        stable_sort(copied.begin(), copied.end());

        int count = 0;
        for (auto i = 0; i < copied.size(); i++)
        {
            if (copied[i] != heights[i])
            {
                count += 1;
            }
        }

        return count;
    }
};
// @lc code=end

int main()
{
    // [2,1,2,1,1,2,2,1]
    // int a[] = {2, 1, 2, 1, 1, 2, 2, 1};
    // Solution{}.heightChecker(vector<int>{a, });
}