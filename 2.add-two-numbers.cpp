/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode();
        auto tail = dummy;
        int up = 0;
        while (l1 || l2) {
            int sum;
            if (!l1) {
                sum = l2->val;
                l2 = l2->next;
            } else if (!l2) {
                sum = l1->val;
                l1 = l1->next;
            } else {
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            sum += up;
            int curr = sum % 10;
            up = sum / 10;
            tail->next = new ListNode(curr);
            tail = tail->next;
        }
        if (up) {
            tail->next = new ListNode(up);
        }
        return dummy->next;
    }
};
// @lc code=end
