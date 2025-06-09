/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-09 08:51:12
 * @LastEditTime: 2025-05-13 15:50:03
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\2.两数相加.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        return dummy->next;
    }
};

/**
 * 使用 C++11 引入的智能指针（如 std::unique_ptr 或者 std::shared_ptr）来管理内存。
 * 这样可以确保在函数结束后，内存会被自动回收。
 */

/**
#include <memory>
using namespace std;

struct ListNode
{
    int val;
    shared_ptr<ListNode> next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, shared_ptr<ListNode> next) : val(x), next(next) {}
};

class Solution
{
public:
    shared_ptr<ListNode> addTwoNumbers(shared_ptr<ListNode> l1, shared_ptr<ListNode> l2)
    {
        auto dummy = make_shared<ListNode>(0);
        auto curr = dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            curr->next = make_shared<ListNode>(sum % 10);
            curr = curr->next;
        }
        return dummy->next;
    }
};
*/
// @lc code=end
