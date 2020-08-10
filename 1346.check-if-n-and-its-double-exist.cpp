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
        bool nums[2001] = {false};
        for (auto i = 0; i < arr.size(); ++i)
        {
            auto n = 2 * arr[i];
            if (n <= 1000 && n >= -1000 && nums[n + 1000])
                return true;

            if (arr[i] % 2 == 0)
            {
                auto m = arr[i] / 2;
                if (m <= 1000 && m >= -1000 && nums[m + 1000])
                    return true;
            }

            nums[arr[i] + 1000] = true;
        }

        return false;
    }
};
// @lc code=end
