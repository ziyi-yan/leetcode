/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;

        /*
            +--------+   +---------+   +----------+   +---------+
            |  curr  +-->+  first  +-->+  second  +-->+  third  |
            +--------+   +---------+   +----------+   +---------+
        */
        for (auto curr = dummy; curr->next && curr->next->next; curr = curr->next->next)
        {
            auto first = curr->next;
            auto second = curr->next->next;
            auto third = curr->next->next->next;

            curr->next = second;
            second->next = first;
            first->next = third;
        }

        return dummy->next;
    }
};
// @lc code=end
