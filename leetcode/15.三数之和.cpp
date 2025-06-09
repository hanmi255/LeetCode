/*** 
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-09 15:48:25
 * @LastEditTime: 2025-05-16 17:23:21
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description: 
 * @FilePath: \LeetCode\15.三数之和.cpp
 * @技术宅拯救世界！！！
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        int len = nums.size();

        // 边界条件
        if (nums.size() < 3)
            return res;

        // 排序（升序）以方便双指针法寻找三元组
        // 算法思想：通过排序将问题转化为两层循环问题，利用双指针法在O(n)时间内找到满足条件的三元组
        sort(nums.begin(), nums.end());

        // 遍历
        for (int i = 0; i < len - 2; i++)
        {
            // 如果当前元素大于0，则跳出循环
            // 因为数组已排序，后续元素只会变大
            if (nums[i] > 0)
                break;

            // 处理重复元素
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 使用双指针
            int left = i + 1, right = len - 1;
            int target = -nums[i];

            while (left < right)
            {
                // 找到三元组
                if (nums[left] + nums[right] == target)
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                // 继续寻找
                else if (nums[left] + nums[right] < target)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};
// @lc code=end
