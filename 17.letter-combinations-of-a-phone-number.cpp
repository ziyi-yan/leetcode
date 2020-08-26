#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        dfs(digits, 0);
        return result;
    }

    void dfs(string &digits, int i)
    {
        if (i >= digits.size())
        {
            result.push_back(curr);
            return;
        }

        auto letters = m[digits[i]];
        for (auto l : letters)
        {
            curr.push_back(l);
            dfs(digits, i + 1);
            curr.pop_back();
        }
    }

private:
    string curr;
    vector<string> result;

    unordered_map<char, string> m = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
};
// @lc code=end
