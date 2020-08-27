#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> result;
        result.push_back(deck[0]);
        for (auto i = 1; i < deck.size(); i++)
        {
            auto back = result.back();
            result.pop_back();
            result.push_front(back);
            result.push_front(deck[i]);
        }
        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end
