#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
class Solution
{
    int k;
    int m;

public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        this->k = k;
        this->m = m;

        for (auto i = 0; i + m <= arr.size(); i++)
            if (find(arr, i))
                return true;
        return false;
    }
    bool find(vector<int> &arr, int start)
    {
        int count = 0;
        for (auto i = 0; i + m <= arr.size();)
        {
            if (compare(arr, i, start))
            {
                count++;
                if (count == k)
                    return true;
                i += m;
            }
            else
            {
                count = 0;
                i++;
            }
        }
        return false;
    }
    bool compare(vector<int> &arr, int lhs, int rhs)
    {
        for (auto i = 0; i < m; i++)
            if (arr[lhs + i] != arr[rhs + i])
                return false;
        return true;
    }
};
// @lc code=end
