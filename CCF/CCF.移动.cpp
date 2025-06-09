/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-06-08 10:31:03
 * @LastEditTime: 2025-06-08 10:31:31
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\CCF.移动.cpp
 * @技术宅拯救世界！！！
 */

// 题目描述:
// 整个实验场地被划分为n×n个方格，从（1,1）到（n,n）进行编号。机器人只能在这些方格间移动，不能走出场地范围。
// 假设机器人当前位于（,9)，那么接下来可以向前后左右任意方向移动一格：
// · 向前移动 f : (x,y)→(x,y+1)
// · 向后移动 b : (x,y) → (x,y-1)
// · 向左移动 1: (x,y) → (x-1,y)
// · 向右移动 r : (x,y)→(x+1,y)
// 特别地，如果移动的目标位置不在场地范围内，则机器人位置保持不变。这样，使用由
// f、b、1 和r 组成的指令序列便可操纵机器人在场地上自由移动。
// 试处理k个查询：每个查询包含一个机器人起始位置（x,y）（1≤x,y≤n）和一个移动指令序列（由fblr
// 四个字母组成的字符串)，输出执行完移动指令后的最终位置。
// 输入格式:
// 从标准输入读入数据。
// 输入的第一行包含空格分隔的两个正整数n和k，分别表示场地大小和查询个数。
// 接下来 k 行：每行包含空格分隔的两个正整数x、y和一个由 fblr
// 四个字母组成的字符串，表示一个查询。
// 输出格式:
// 输出到标准输出。 每个查询输出一行：包含空格分隔的两个正整数
// x和y，表示对应查询的最终位置。
// 样例输入:
// 3 2
// 1 1 ffrrbbll
// 3 3 frbl
// 样例输出:
// 1 1
// 2 2

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x, y;
        string commands;
        cin >> x >> y >> commands;

        for (const auto &cmd : commands) {
            switch (cmd) {
            case 'f':
                if (y < n) {
                    y++;
                }
                break;
            case 'b':
                if (y > 1) {
                    y--;
                }
                break;
            case 'l':
                if (x > 1) {
                    x--;
                }
                break;
            case 'r':
                if (x < n) {
                    x++;
                }
                break;
            }
        }
        cout << x << " " << y << endl;
    }

    return 0;
}
