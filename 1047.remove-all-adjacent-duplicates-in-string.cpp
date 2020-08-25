#include <string>
using namespace std;
/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicates(string S)
    {
        if (S.empty())
            return "";

        string temp;
        string *todo = &S, *done = &temp;
        do
        {
            done->resize(0);
            remove(*todo, *done);

            auto temp = todo;
            todo = done;
            done = temp;
        } while (todo->size() != done->size());

        return *todo;
    }

private:
    void remove(string &S, string &removed)
    {
        char prev = S[0];
        auto i = 1;
        while (i <= S.size())
        {
            if (S[i] != prev || i == S.size())
                removed.push_back(prev);
            else
                i++;

            if (i < S.size())
                prev = S[i];
            i++;
        }
    }
};
// @lc code=end
int main()
{
    auto result = Solution().removeDuplicates("aaaaaaaaa");
}