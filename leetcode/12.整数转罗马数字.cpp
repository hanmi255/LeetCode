/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> intToRomanPair = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string result = "";

        for (const auto &pair : intToRomanPair) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }

            if (num == 0)
                break;
        }

        return result;
    }
};
// @lc code=end
