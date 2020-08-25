#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        // NOTE: Convert the equality into a minus of two at-most result.
        return atMost(A, S) - atMost(A, S - 1);
    }

private:
    int atMost(vector<int> &A, int S)
    {
        if (S < 0)
            return 0;
        int prefix_sum = 0;
        int count = 0;
        for (auto i = 0, j = 0; j < A.size();)
        {
            prefix_sum += A[j++];
            while (prefix_sum > S)
                prefix_sum -= A[i++];
            count += j - i;
        }
        return count;
    }
};
// @lc code=end
