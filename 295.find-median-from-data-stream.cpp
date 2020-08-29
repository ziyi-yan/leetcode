#include <queue>
#include <string>
using namespace std;
/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!max_heap.size())
            max_heap.push(num);
        else if (num < max_heap.top())
            max_heap.push(num);
        else
            min_heap.push(num);

        while (diff(min_heap.size(), max_heap.size()) > 1)
            if (min_heap.size() > max_heap.size())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            else
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
    }

    double findMedian()
    {
        if (min_heap.size() == max_heap.size())
            return min_heap.top() + (max_heap.top() - min_heap.top()) / 2.0;
        else if (min_heap.size() < max_heap.size())
            return max_heap.top();
        else
            return min_heap.top();
    }

private:
    int64_t diff(int64_t x, int64_t y)
    {
        auto diff = x - y;
        if (diff >= 0)
            return diff;
        else
            return -diff;
    }
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
int main()
{
    double median;
    auto f = new MedianFinder();
    f->addNum(-1);
    median = f->findMedian();
    f->addNum(-2);
    median = f->findMedian();
    f->addNum(-3);
    median = f->findMedian();
    f->addNum(-4);
    median = f->findMedian();
    f->addNum(-5);
    median = f->findMedian();
}
