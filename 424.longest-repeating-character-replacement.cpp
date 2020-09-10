#include <string>
using namespace std;
/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int count[26] = {0};
        int max_cnt = 0;
        int max_len = 0;
        int i = 0, j = 0;
        while (j < s.size()) {
            max_cnt = max(max_cnt, ++count[s[j++] - 'A']);
            if (j - i - max_cnt > k) {
                --count[s[i++] - 'A'];
                // NOTE: max_cnt can be invalid when we shrink the start index
                // `i`. But it won't affect the correctness because each time
                // max_len got extended from max_cnt getting extended and it
                // happens if and only if a new majority appears in the sliding
                // window.
            }
            max_len = max(max_len, j - i);
        }
        return max_len;
    }
};
// @lc code=end
