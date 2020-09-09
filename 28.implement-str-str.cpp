#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        vector<int> next(needle.size());
        next[0] = 0;
        int i = 0, j = 1;
        while (j < needle.size()) {
            if (needle[i] == needle[j]) {
                next[j] = i + 1;
                i++;
                j++;
            } else {
                if (i != 0) {
                    i = next[i - 1];
                } else {
                    next[j] = 0;
                    j++;
                }
            }
        }

        i = 0;
        j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    j = next[j - 1];
                } else {
                    i++;
                }
            }
        }
        if (j == needle.size()) {
            return i - j;
        }
        return -1;
    }
};
// @lc code=end
int main() {
    auto result = Solution().strStr("hello", "agctagcagctagctg");
    return 0;
}
