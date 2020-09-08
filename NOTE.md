# 优化点

1. 动态规划的空间复杂度是否可以优化，要看他的状态转移方程。
2. 优化空间之后的 DP，需要注意迭代的顺序，不能在计算完之前把还需要的前一个 DP 值覆盖了。例如，416。

# Tips

1. memoization DFS use python with @lru_cache decorator
2. max_element() to get the max element from C++ container
