/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToIntMap = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        int result = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (i < len - 1 && romanToIntMap[s[i]] < romanToIntMap[s[i + 1]]) {
                result -= romanToIntMap[s[i]];
            } else {
                result += romanToIntMap[s[i]];
            }
        }
        return result;
    }
};
// @lc code=end
