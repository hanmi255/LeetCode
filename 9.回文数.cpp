/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-16 13:45:11
 * @LastEditTime: 2025-05-16 13:45:28
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\9.回文数.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        string str = to_string(x);

        int length = str.length();
        int compareCount = length / 2;

        for (int i = 0; i < compareCount; i++)
        {
            if (str[i] != str[length - 1 - i])
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
