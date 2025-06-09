/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
        vector<string> rows(numRows);
        int cycle = 2 * numRows - 2; // Z字形的周期

        for (int i = 0; i < s.length(); i++)
        {
            int row = i % cycle; // 当前字符所在的行
            if (row >= numRows)
            {
                row = cycle - row; // 反向行
            }
            rows[row] += s[i]; // 加入到对应的行
        }
        string res;
        for (const auto &row : rows)
            res += row;
        return res;
    }
};
// @lc code=end
