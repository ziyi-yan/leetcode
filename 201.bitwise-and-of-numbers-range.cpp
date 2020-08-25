/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        // If m is not equal to n, there must be one odd number and one even
        // number in the range of [m, n] and the last bit of the AND result
        // should be zero. So, we shift one bit right and repeat the process
        // until m equals to n and we restore the value via shifting left.
        auto count = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};
// @lc code=end
int main()
{
    auto result = Solution().rangeBitwiseAnd(5, 7);
}