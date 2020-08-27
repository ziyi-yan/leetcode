#include <vector>
using namespace std;

/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        if (matrix[0].empty())
            return false;

        // treat matrix as a 1D array and use binary search
        int lo = 0;
        int hi = matrix.size() * matrix[0].size() - 1;
        while (lo + 1 < hi)
        {
            auto mid = lo + (hi - lo) / 2;
            auto val = get(matrix, mid);
            if (val == target)
                return true;
            if (val < target)
                lo = mid;
            else
                hi = mid;
        }
        if (get(matrix, lo) == target)
            return true;
        if (get(matrix, hi) == target)
            return true;
        return false;
    }

    int get(vector<vector<int>> &matrix, int index)
    {
        auto num_cols = matrix[0].size();
        return matrix[index / num_cols][index % num_cols];
    }
};
// @lc code=end
