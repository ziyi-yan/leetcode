#include <string>
#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        int largest_l = 0;
        int largest_r = 0;

        int n = s.size();
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            // k is the minimal possible expansion length centered at i
            int k = i > r ? 1 : min(r - i + 1, d1[l + (r - i)]);
            while (i + k < n && i - k >= 0 && s[i + k] == s[i - k]) {
                k++;
            }
            d1[i] = k;
            if (i + k - 1 > r) {
                r = i + k - 1;
                l = i - k + 1;
            }
            if (r - l > largest_r - largest_l) {
                largest_l = l;
                largest_r = r;
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
            if (r - l > largest_r - largest_l) {
                largest_l = l;
                largest_r = r;
            }
        }
        return s.substr(largest_l, largest_r - largest_l + 1);
    }
};
// @lc code=end
int main() {
    // auto result =
    // Solution().longestPalindrome("aaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaaaaaabbbbbbbbbbccccccccccddddddddddeeeeeeeeeeffffffffffgggggggggghhhhhhhhhhiiiiiiiiiijjjjjjjjjjkkkkkkkkkkllllllllllmmmmmmmmmmnnnnnnnnnnooooooooooppppppppppqqqqqqqqqqrrrrrrrrrrssssssssssttttttttttuuuuuuuuuuvvvvvvvvvvwwwwwwwwwwxxxxxxxxxxyyyyyyyyyyzzzzzzzzzzyyyyyyyyyyxxxxxxxxxxwwwwwwwwwwvvvvvvvvvvuuuuuuuuuuttttttttttssssssssssrrrrrrrrrrqqqqqqqqqqppppppppppoooooooooonnnnnnnnnnmmmmmmmmmmllllllllllkkkkkkkkkkjjjjjjjjjjiiiiiiiiiihhhhhhhhhhggggggggggffffffffffeeeeeeeeeeddddddddddccccccccccbbbbbbbbbbaaaa");
    auto result = Solution().longestPalindrome("babad");
}
