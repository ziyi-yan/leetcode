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
        // because of 1 <= heights[i] <= 100, we can use a finite-sized array to
        // count the number of occurrences of each number. This statistics will
        // imply its order if it is sorted.
        //
        // related: counting sort, bucket sort, radix sort.
        int height_count[101] = {}; // initialize all elements as zeros

        for (auto h : heights)
        {
            height_count[h] += 1;
        }

        int count = 0;
        // current scanning index of the heights array.
        int curr = 0;
        for (auto h = 0; h < 101; h++)
        {
            while (height_count[h] > 0)
            {
                // When the code reach here, it means that the heights[curr]
                // should be h.
                // If it's not that case, we need to increment the misplaced count.
                if (heights[curr] != h)
                {
                    count += 1;
                }
                curr += 1;
                height_count[h] -= 1;
            }
        }
        return count;
    }
};
// @lc code=end

int main()
{
    // [2,1,2,1,1,2,2,1]
    int a[] = {2, 1, 2, 1, 1, 2, 2, 1};
    auto v = vector<int>{a, a + sizeof(a) / sizeof(a[0])};

    auto result = Solution{}.heightChecker(v);
    printf("%d\n", result);
}