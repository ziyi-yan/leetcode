#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            // k is the minimal possible expansion length centered at i
            int k = i > r ? 1 : min(r - i + 1, d1[l + (r - i)]);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k - 1 > r) {
                r = i + k;
                l = i - k;
            }
        }
        vector<int> d2(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = i > r ? 0 : min(r - i + 1, d2[l + r - i + 1]);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k - 1 > r) {
                l = i - k - 1;
                r = i + k;
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += d1[i] + d2[i];
        }
        return result;
    }
};
// @lc code=end
