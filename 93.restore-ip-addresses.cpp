#include <vector>
#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        auto v = vector<string>{};
        backtrace(v, "", s, 0, 0);
        return v;
    }

    const int LAST_SEGMENT = 3;

    void backtrace(vector<string> &result, string curr_result, string s, int start_idx, int segment_num)
    {
        if (segment_num == LAST_SEGMENT)
        {
            // check final segment with all the remaining digits
            auto segment_len = s.size() - start_idx;
            if (segment_len > 3 || segment_len <= 0)
                return;

            auto segment = s.substr(start_idx, segment_len);
            if (segment.size() > 1 && segment[0] == '0')
                return;
            if (stoi(segment) > 255)
                return;

            result.push_back(curr_result.append(segment));
        }
        else
        {
            for (auto segment_len = 1; segment_len <= 3 && start_idx + segment_len <= s.size(); segment_len++)
            {
                auto segment = s.substr(start_idx, segment_len);
                if (segment.size() > 1 && segment[0] == '0')
                    return;
                if (stoi(segment) > 255)
                    return;

                backtrace(result, curr_result + segment + ".", s, start_idx + segment_len, segment_num + 1);
            }
        }
    }
};
// @lc code=end

int main()
{
    auto result = Solution{}.restoreIpAddresses("010010");
}