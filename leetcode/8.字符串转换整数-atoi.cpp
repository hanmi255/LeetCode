/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int length = s.length();
        int index = 0;

        // 检查空格
        while (index < length && s[index] == ' ') {
            index++;
        }

        if (index == length) {
            return 0;
        }

        // 检查符号
        int sign = 1;
        if (s[index] == '+' || s[index] == '-') {
            sign = s[index] == '+' ? 1 : -1;
            index++;
        }

        // 检查数字并计算结果
        int result = 0;
        while (index < length && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            index++;
        }

        return result * sign;
    }
};
// @lc code=end

