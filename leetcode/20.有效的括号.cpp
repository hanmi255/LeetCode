/*** 
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-13 10:07:34
 * @LastEditTime: 2025-05-16 17:26:29
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description: 
 * @FilePath: \LeetCode\20.有效的括号.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        for (char c : s)
        {
            if (mp.count(c))
            {
                if (st.empty() || st.top() != mp[c])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.empty();
    }
};
// @lc code=end
