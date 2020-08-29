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
        lo.push(num);
        hi.push(lo.top());
        lo.pop();

        if (lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian()
    {
        // lo.size() is not smaller than hi.size()
        return lo.size() > hi.size() ? lo.top() : lo.top() + (hi.top() - lo.top()) / 2.0;
    }

private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
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
