/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-11 11:35:33
 * @LastEditTime: 2025-05-20 17:21:52
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\239.滑动窗口最大值.cpp
 * @技术宅拯救世界！！！
 */
/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2024-09-11 11:35:33
 * @LastEditTime: 2025-05-16 19:07:11
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\239.滑动窗口最大值.cpp
 * @技术宅拯救世界！！！
 */

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> result;
        deque<int> q; // 滑动窗口

        for (int i = 0; i < nums.size(); i++) {
            // 移除不在当前窗口内的元素索引
            while (!q.empty() && q.front() < i - k + 1) {
                q.pop_front();
            }
            // 移除比当前元素小的所有元素索引
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            // 添加当前元素索引
            q.push_back(i);

            // 当窗口大小达到k时，将当前窗口最大值加入结果
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
// @lc code=end
