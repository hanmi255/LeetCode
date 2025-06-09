/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-11 16:32:29
 * @LastEditTime: 2025-05-13 15:53:46
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\3.无重复字符的最长子串.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int maxLength = 0;

        unordered_map<char, int> charMap;

        // 滑动窗口左边界
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            char currentChar = s[right];
            if (charMap.find(currentChar) != charMap.end())
            {
                // 如果当前字符在map中存在，则更新左边界
                left = max(left, charMap[currentChar] + 1);
            }

            // 更新字符位置
            charMap[currentChar] = right;
            // 更新最大长度
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
// @lc code=end
