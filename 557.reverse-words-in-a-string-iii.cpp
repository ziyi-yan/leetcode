#include <string>
using namespace std;
/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        int l = 0, r = 0;
        while (l < s.size())
        {
            while (r < s.size() && s[r] != ' ')
                r++;
            reverse(s, l, r);
            r++;
            l = r;
        }
        return s;
    }
    void reverse(string &s, int l, int r)
    {
        char temp;
        r--;
        while (l < r)
        {
            temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
};
// @lc code=end
