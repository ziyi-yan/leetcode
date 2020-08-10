#include <vector>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> set;
        for (auto i = 0; i < arr.size(); ++i)
        {
            auto n = 2 * arr[i];
            if (set.find(n) != set.end())
                return true;

            if (arr[i] % 2 == 0)
            {
                auto m = arr[i] / 2;
                if (set.find(m) != set.end())
                    return true;
            }

            set.insert(arr[i]);
        }

        return false;
    }
};
// @lc code=end
