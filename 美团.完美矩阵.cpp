/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-17 09:38:31
 * @LastEditTime: 2025-05-17 09:41:46
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\美团.完美矩阵.cpp
 * @技术宅拯救世界！！！
 */

/*
小美的平衡矩阵
 * 题目内容:
    小美拿到了一个n∗n的矩阵，其中每个元素是 0 或者 1。
    小美认为一个矩形区域是完美的，当且仅当该区域内 0 的数量恰好等于 1 的数量。
    现在，小美希望你回答有多少个i∗i的完美矩形区域。你需要回答1≤i≤n的所有答案。
 *时间限制：C/C++ 1秒，其他语言2秒
 *空间限制：C/C++ 256M，其他语言512M
 *输入描述：
    第一行输入一个正整数n，代表矩阵大小。
    接下来的n行，每行输入一个长度为n的 01 串，用来表示矩阵。
 *输出描述：
    输出n行，第i行输出i*i的完美矩形区域的数量。
 *示例1
    输入例子：
    4
    1010
    0101
    1100
    0011
    输出例子：
    0
    7
    0
    1
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 使用前缀和技术
int main()
{
    int n;
    cin >> n;

    // 读取二维矩阵
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = row[j] - '0';
        }
    }

    // 计算前缀和
    // 初始化前缀和矩阵
    // prefixSum[i][j]表示从(0,0)到(i-1,j-1)这个矩形区域中所有元素的和。
    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    // 对每种i*i大小的矩阵进行统计
    for (int i = 1; i <= n; ++i)
    {
        int count = 0;

        // 提前判断：i为奇数则跳过
        if (i % 2 == 1)
        {
            cout << 0 << endl;
            continue;
        }

        for (int r = 1; r <= n - i + 1; ++r)
        {
            for (int c = 1; c <= n - i + 1; ++c)
            {
                // 计算子矩阵中1的数量
                // 左上角位置(r,c) 和右下角位置(r+i-1,c+i-1)
                // 减去上方与左侧区域和，加上左上角区域和
                int onesCount = prefixSum[r + i - 1][c + i - 1] - prefixSum[r - 1][c + i - 1] -
                                prefixSum[r + i - 1][c - 1] + prefixSum[r - 1][c - 1];
                // 检查是否为完美矩形
                if (onesCount == i * i / 2)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

// 使用暴力解法
int main()
{
    int n;
    cin >> n;

    // 读取二维矩阵
    std::vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = row[j] - '0';
        }
    }

    // 暴力解法
    for (int size = 1; size <= n; size++)
    {
        int count = 0;
        // 提前判断：size为奇数则跳过
        if (size % 2 == 1)
        {
            cout << 0 << endl;
        }

        // 判断所有可能的矩形
        for (int r = 0; r <= n - size; r++)
        {
            for (int c = 0; c <= n - size; c++)
            {
                int onesCount = 0;
                // 统计矩阵中1的数量
                for (int i = r; i < r + size; i++)
                {
                    for (int j = c; j < c + size; j++)
                    {
                        if (matrix[i][j] == 1)
                        {
                            onesCount++;
                        }
                    }
                }
                if (onesCount == size * size / 2)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}