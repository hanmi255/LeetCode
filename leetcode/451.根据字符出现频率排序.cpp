/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-13 12:59:12
 * @LastEditTime: 2025-05-20 17:17:10
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\451.根据字符出现频率排序.cpp
 * @技术宅拯救世界！！！
 */
/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-13 12:59:12
 * @LastEditTime: 2025-05-16 23:41:44
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\451.根据字符出现频率排序.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        // 统计字符出现的频率
        unordered_map<char, int> map;
        for (const auto &c : s) {
            map[c]++;
        }

        // 转化成vector方便排序
        vector<pair<char, int>> vec = {};
        for (const auto &[c, count] : map) {
            vec.emplace_back(c, count);
        }

        // 按照频率降序排序
        sort(vec.begin(), vec.end(),
             [](const pair<char, int> &a, const pair<char, int> &b) {
                 return a.second > b.second;
             });

        // 构造结果字符串
        string res = "";
        for (const auto &[c, count] : vec) {
            res.append(count, c);
        }

        return res;
    }
};
// @lc code=end
