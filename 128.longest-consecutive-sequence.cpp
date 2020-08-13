#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
// UnionFind implements union-find data structure.
// It uses weighted quick-union with path compression.
class UnionFind
{
public:
    UnionFind(size_t size) : parents_(size), sizes_(size, 1)
    {
        for (auto i = 0; i < parents_.size(); i++)
            parents_[i] = i;
    }

    int root(int i)
    {
        while (parents_[i] != i)
        {
            parents_[i] = parents_[parents_[i]];
            i = parents_[i];
        }
        return i;
    }

    bool find(int p, int q)
    {
        return root(p) == root(q);
    }

    void unite(int p, int q)
    {
        int i = root(p);
        int j = root(q);

        if (sizes_[i] < sizes_[j])
        {
            parents_[i] = j;
            sizes_[j] += sizes_[i];
        }
        else
        {
            parents_[j] = i;
            sizes_[i] += sizes_[j];
        }
    }

    int size(int i)
    {
        return sizes_[root(i)];
    }

private:
    // the parent of i.
    vector<int> parents_;
    // the size of each root.
    vector<int> sizes_;
};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> indices;
        UnionFind uf(nums.size());
        int largest = 0;

        for (auto i = 0; i < nums.size(); i++)
        {
            auto n = nums[i];
            if (indices.find(n) != indices.end())
                continue;

            indices[n] = i;
            if (indices.find(n - 1) != indices.end())
            {
                uf.unite(indices[n - 1], i);
            }
            if (indices.find(n + 1) != indices.end())
            {
                uf.unite(indices[n + 1], i);
            }

            auto size = uf.size(i);
            if (size > largest)
                largest = size;
        }

        return largest;
    }
};
// @lc code=end
