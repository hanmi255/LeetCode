/*** 
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-11 11:13:29
 * @LastEditTime: 2025-05-20 17:22:15
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description: 
 * @FilePath: \LeetCode\387.字符串中的第一个唯一字符.cpp
 * @技术宅拯救世界！！！
 */
/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-11 11:13:29
 * @LastEditTime: 2025-05-16 20:45:46
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\387.字符串中的第一个唯一字符.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        // 遍历字符串，统计每个字符的频率
        for (int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        // 再次遍历字符串，寻找第一个频率为1的字符
        for (int i = 0; i < n; i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        // 如果没有找到唯一字符，返回-1
        return -1;
    }
};
// @lc code=end
