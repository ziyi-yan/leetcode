#include <string>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
    bool compareCount(unordered_map<char, int> &lhs,
                      unordered_map<char, int> &rhs) {
        for (auto x : lhs) {
            auto key = x.first;
            auto val = x.second;
            if (rhs.find(key) == rhs.end() || rhs[key] != val) {
                return false;
            }
        }
        return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int m = s1.size();
        int n = s2.size();
        unordered_map<char, int> s1_cnt;
        unordered_map<char, int> s2_cnt;
        for (auto ch : s1) {
            s1_cnt[ch]++;
        }
        for (auto i = 0; i < n; i++) {
            s2_cnt[s2[i]]++;
            if (i >= m - 1) {
                if (i >= m) {
                    s2_cnt[s2[i - m]]--;
                }
                if (compareCount(s1_cnt, s2_cnt)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
