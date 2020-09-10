#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_map<char, int> m;
        int longest = 0;
        while (j < s.size()) {
            if (m.find(s[j]) != m.end()) {
                while (i <= m[s[j]]) {
                    m.erase(s[i]);
                    i++;
                }
            }
            m[s[j]] = j;
            j++;
            longest = max(longest, j - i);
        }
        return longest;
    }
};
// @lc code=end
