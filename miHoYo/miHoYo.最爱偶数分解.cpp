/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-17 18:08:03
 * @LastEditTime: 2025-05-19 19:28:30
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\miHoYo.最爱偶数分解.cpp
 * @技术宅拯救世界！！！
 */
/*
最爱偶数分解
 * 题目内容:
    米小游非常喜欢偶数，尤其是能被2整除很多次的偶数。对于一个偶数n，米小游定义其"喜好值"为n能被2整除的次数。
    例如，对于数字8，可以被2整除3次（8/2=4，4/2=2，2/2=1），所以喜好值为3。
    现在，给定一个区间[l, r]，请你找出区间内所有偶数的最大喜好值和所有偶数的喜好值总和。
 * 输入描述:
    一行两个整数l和r，表示区间的左右边界（1 ≤ l ≤ r ≤ 10^5）。
 * 输出描述:
    输出两个整数，分别表示区间内偶数的最大喜好值和所有偶数的喜好值总和，用空格分隔。
 * 样例1:
    输入
    1 10
    输出
    3 11
 * 说明:
    区间[1,10]中的偶数有：2（喜好值1），4（喜好值2），6（喜好值1），8（喜好值3），10（喜好值1）
    最大喜好值为3，喜好值总和为1+2+1+3+1=8。
 * 样例2:
    输入
    11 15
    输出
    1 3
 * 说明:
    区间[11,15]中的偶数有：12（喜好值2），14（喜好值1）
    最大喜好值为2，喜好值总和为2+1=3。
*/
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;

    // 存储区间内所有正整数
    int n = r - l + 1;
    vector<int> arr(n);
    for (int i = l; i <= r; i++)
    {
        arr[i] = i;
    }

    vector<pair<int, int>> likePair;
    for (int i = 0; i < n; i++)
    {
        // 奇数则跳过
        if (arr[i] % 2 != 0)
        {
            continue;
        }

        int num = arr[i];
        int likeValue = 0;
        while (num % 2 == 0)
        { // 当数字能被2整除时才进入循环
            likeValue++;
            num /= 2;
        }
        likePair.emplace_back(arr[i], likeValue);
    }

    int maxLike = 0;
    long long totalLike = 0;

    // 检查是否存在偶数
    if (!likePair.empty())
    {
        // 寻找最大喜好值
        for (auto &p : likePair)
        {
            maxLike = max(maxLike, p.second);
            totalLike += p.second;
        }
    }

    cout << maxLike << " " << totalLike;

    return 0;
}