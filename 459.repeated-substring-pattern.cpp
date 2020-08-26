#include <string>
using namespace std;
/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        // If s is constructed by a multiple substring pattern,
        // we can find the s itself in (s + s) at the index before s.size().
        auto concat = s + s;
        return concat.find(s, 1) < s.size();
    }
};
// @lc code=end
