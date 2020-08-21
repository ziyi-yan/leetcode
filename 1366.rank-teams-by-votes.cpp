#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
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
        {
            return "";
        }

        auto numTeams = votes[0].size();
        vector<int> teams;
        unordered_map<char, vector<int>> scores;
        for (auto vote : votes)
        {
            for (auto rank = 0; rank < numTeams; rank++)
            {
                auto team = vote[rank];
                if (scores.find(team) == scores.end())
                {
                    scores[team].resize(numTeams);
                    teams.push_back(team);
                }
                scores[team][rank] += 1;
            }
        }

        sort(teams.begin(), teams.end(), [&](char lhs, char rhs) {
            auto l = scores[lhs];
            auto r = scores[rhs];
            return compareScores(lhs, l, rhs, r);
        });

        return string(teams.begin(), teams.end());
    }

private:
    bool compareScores(char lteam, vector<int> l, char rteam, vector<int> r)
    {
        for (auto i = 0; i < l.size(); i++)
        {
            if (l[i] > r[i])
                return true;
            if (l[i] < r[i])
                return false;
        }
        return lteam < rteam;
    }
};
// @lc code=end
int main()
{
    vector<string> teams = {"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"};
    auto result = Solution{}.rankTeams(teams);
}