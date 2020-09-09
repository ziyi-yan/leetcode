#include <algorithm>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
   public:
    string reverseWords(string s) {
        int l = 0, r = 0;
        while (l < s.size()) {
            while (r < s.size() && s[r] != ' ') r++;
            reverse(s.begin() + l, s.begin() + r);
            r += 1;
            l = r;
        }
        return s;
    }
};
// @lc code=end
