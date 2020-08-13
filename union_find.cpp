#include <vector>
using namespace std;

// UnionFind implements union-find data structure.
// It implements WQUPC (weighted quick-union with path compression).
//
// Reference: https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
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
            // NOTE: Path Compression
            // If i is not a root, update its root to the root of its parent.
            // This improvement can keep the tree almost completely flat.
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

        // NOTE: Weighted Quick-Union
        // Keep track of size of each component and then
        // balance by linking small tree below large one
        // to avoid tall trees.
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