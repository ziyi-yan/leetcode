#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// UnionFind implements union-find data structure.
// It uses weighted quick-union with path compression.
class Solution
{
public:
    // O(n) OPTIMIZATION:
    // use customized array and store the left or right end
    // information and only update the size of the leftmost and rightmost
    // elements.
    // Because we only need to care about the ones less than the leftmost one
    // or those larger than the rightmost for finding the .
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        unordered_map<int, SizePosition> positions;

        int largest = 1;

        for (auto i = 0; i < nums.size(); i++)
        {
            auto n = nums[i];
            if (positions.find(n) != positions.end())
                continue;

            positions[n] = SizePosition{.size = 1, .position = Position::Inside};

            if (positions.find(n - 1) != positions.end())
            {
                auto size = unite(positions, n - 1, n);

                if (size > largest)
                    largest = size;
            }
            if (positions.find(n + 1) != positions.end())
            {
                auto size = unite(positions, n, n + 1);

                if (size > largest)
                    largest = size;
            }
        }

        return largest;
    }

private:
    enum class Position
    {
        Left,
        Right,
        Inside
    };
    struct SizePosition
    {
        int size;
        Position position; // left (-1) or right (1) or inside (0).
    };

    int unite(unordered_map<int, SizePosition> &positions, int right_end, int left_end)
    {
        if (positions[right_end].position == Position::Left || positions[left_end].position == Position::Right)
            return 0;
        auto left_size = positions[left_end].size;
        auto right_size = positions[right_end].size;
        auto size = left_size + right_size;
        positions[right_end - (right_size - 1)].size = size;
        positions[right_end - (right_size - 1)].position = Position::Left;
        positions[left_end + (left_size - 1)].size = size;
        positions[left_end + (left_size - 1)].position = Position::Right;
        return size;
    }
};
// @lc code=end
int main()
{
    vector<int> input = {100, 4, 200, 1, 3, 2};
    auto result = Solution().longestConsecutive(input);
}