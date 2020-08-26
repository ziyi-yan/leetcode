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

        Point left_top = {.x = 0, .y = 0};
        Point right_bottom = {.x = matrix.size() - 1, .y = matrix[0].size() - 1};
        while (left_top.x + 1 < right_bottom.x || left_top.y + 1 < right_bottom.y)
        {
            auto middle = calculateMiddle(left_top, right_bottom);
            if (matrix[middle.x][middle.y] == target)
                return true;
            else if (matrix[middle.x][middle.y] > target)
            {
                right_bottom = middle;
            }
            else
                left_top = middle;
        }
        if (matrix[left_top.x][left_top.y] == target)
            return true;
        if (matrix[right_bottom.x][right_bottom.y] == target)
            return true;

        if (matrix[left_top.x][right_bottom.y] == target)
            return true;
        if (matrix[right_bottom.x][left_top.y] == target)
            return true;

        return false;
    }

private:
    struct Point
    {
        size_t x, y;

        bool operator<(const Point &o)
        {
            return tie(x, y) < tie(o.x, o.y);
        }
    };
    Point calculateMiddle(Point l, Point r)
    {
        auto p = Point{.x = l.x + (r.x - l.x) / 2, .y = l.y + (r.y - l.y) / 2};
        return p;
    }
};
// @lc code=end
int main()
{
    vector<vector<int>> input = {{1, 2, 3, 4, 5},
                                 {6, 7, 8, 9, 10},
                                 {11, 12, 13, 14, 15},
                                 {16, 17, 18, 19, 20},
                                 {21, 22, 23, 24, 25}};
    int target = 15;
    auto result = Solution().searchMatrix(input, target);
}