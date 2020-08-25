#include <string>
using namespace std;
/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        auto i = 0;
        for (auto j = 0; j < s.size(); i++, j++)
        {
            s[i] = s[j];
            if (i > 0 && s[i - 1] == s[i])
                i -= 2;
        }
        return s.substr(0, i);
    }
};
// @lc code=end
int main()
{
    auto result = Solution().removeDuplicates("aaaaaaaaa");
}