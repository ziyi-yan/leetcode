#include <vector>
#include <tuple>
using namespace std;
/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
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

        this->target = target;

        return search(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1);
    }

private:
    int target;

    bool search(vector<vector<int>> &matrix, int left, int top, int right, int bottom)
    {
        if (left > right || top > bottom)
            return false;
        if (target < matrix[top][left] || target > matrix[bottom][right])
            return false;
        int mid = left + (right - left) / 2;
        int row = top;
        while (row <= bottom && matrix[row][mid] <= target)
        {
            if (matrix[row][mid] == target)
                return true;
            row++;
        }
        // matrix[row-1][mid] < target < matrix[row][mid]
        return search(matrix, left, row, mid - 1, bottom) || search(matrix, mid + 1, top, right, row - 1);
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> input = {{1, 1}};
    int target = 1;
    auto result = Solution{}.searchMatrix(input, target);
}