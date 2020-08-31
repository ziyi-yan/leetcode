#include <string>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";

        int longest = 1;
        string result = s.substr(0, 1);
        int curr = 1;
        int n = s.size();

        for (auto i = 1; i < n; i++)
        {
            if (i - 1 - curr >= 0 && s[i] == s[i - 1 - curr])
            {
                curr += 2;
            }
            else if (curr == 1 && s[i] == s[i - 1])
            {
                curr += 1;
            }
            else
            {
                i -= curr / 2;
                curr = 1;
            }

            if (curr > longest)
            {
                longest = curr;
                result = s.substr(i - curr + 1, curr);
            }
        }

        curr = 1;
        for (auto i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
            {
                curr++;
                if (curr > longest)
                {
                    longest = curr;
                    result = s.substr(i - curr + 1, curr);
                }
            }
            else
            {
                curr = 1;
            }
        }
        return result;
    }
};
// @lc code=end
int main()
{
    auto result = Solution().longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa");
}
