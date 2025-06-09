/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // 双指针法
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right)
        {
            // 计算当前面积
            int area = (right - left) * min(height[left], height[right]);
            // 更新最大面积
            max_area = max(max_area, area);
            // 移动指针
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end
