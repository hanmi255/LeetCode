/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }; */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;

        // 保存第二个节点作为新的头结点
        ListNode *newHead = head->next;

        // 递归处理后续部分
        head->next = swapPairs(newHead->next);

        // 第二个节点指向原先头结点
        newHead->next = head;

        // 返回新头结点
        return newHead;
    }
};
// @lc code=end
