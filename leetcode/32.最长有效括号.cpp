/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-13 13:55:03
 * @LastEditTime: 2025-05-20 17:21:14
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\32.最长有效括号.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; // 栈存放索引
        int maxlen = 0;
        st.push(-1); // 栈底元素为-1
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // 左括号入栈
            } else {
                st.pop(); // 栈顶元素出栈
                if (st.empty()) {
                    st.push(i); // 栈空时，右括号入栈
                } else {
                    maxlen = max(maxlen, i - st.top()); // 计算当前有效括号长度
                }
            }
        }
        return maxlen;
    }
};
// @lc code=end
