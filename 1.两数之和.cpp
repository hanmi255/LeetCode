/*** 
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-07 16:27:23
 * @LastEditTime: 2025-05-13 12:58:36
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description: 
 * @FilePath: \LeetCode\1.两数之和.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.find(target - nums[i]) != hash.end())
            {
                res.push_back(hash[target - nums[i]]);
                res.push_back(i);
            }
            hash[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end