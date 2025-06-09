/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#define INT_MAX 2147483647
#define INT_MIN -2147483648

class Solution
{
public:
    int reverse(int x)
    {
        long long res = 0;
        if (x == 0)
            return 0;
        while (x != 0)
        {
            int digit = x % 10;
            res = res * 10 + digit;
            x /= 10;
        }
        if (res > INT_MAX || res < INT_MIN)
            return 0;

        return static_cast<int>(res);  // 转换类型 避免溢出
    }
};
// @lc code=end
