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

        // Search from left-bottom corner to right-top.
        // Each step we can trim O(m) or O(n) elements.
        int row = matrix.size() - 1;
        int col = 0;
        while (row >= 0 && col < matrix[0].size())
        {
            if (matrix[row][col] == target)
                return true;

            if (matrix[row][col] < target)
                col++;
            else
                row--;
        }
        return false;
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> input = {{1, 4, 7, 11, 15},
                                 {2, 5, 8, 12, 19},
                                 {3, 6, 9, 16, 22},
                                 {10, 13, 14, 17, 24},
                                 {18, 21, 23, 26, 30}};
    int target = 5;
    auto result = Solution{}.searchMatrix(input, target);
}