#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
/*
 * @lc app=leetcode id=1366 lang=cpp
 *
 * [1366] Rank Teams by Votes
 */

// @lc code=start
class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {
        if (votes.empty())
            return "";
        if (votes.size() == 1)
            return votes[0];

        auto numTeams = votes[0].size();
        vector<double> powers(numTeams, 0.0);
        double scores[26] = {0.0};
        for (auto vote : votes)
        {
            for (auto rank = 0; rank < numTeams; rank++)
            {
                auto team = vote[rank];
                scores[team - 'A'] += power(powers, votes.size() + 1, (numTeams - 1 - rank));
            }
        }

        sort(votes[0].begin(), votes[0].end(), [&](char lhs, char rhs) {
            auto l = scores[lhs - 'A'];
            auto r = scores[rhs - 'A'];
            return compareScores(lhs, l, rhs, r);
        });

        return string(votes[0].begin(), votes[0].end());
    }

private:
    bool compareScores(char lteam, double l, char rteam, double r)
    {
        if (l > r)
            return true;
        if (l < r)
            return false;
        return lteam < rteam;
    }

    double power(vector<double> &powers, double base, double exp)
    {
        if (powers[exp] == 0.0)
            powers[exp] = pow(base, exp);
        return powers[exp];
    }
};
// @lc code=end
int main()
{
    vector<string> teams = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    auto result = Solution{}.rankTeams(teams);
}