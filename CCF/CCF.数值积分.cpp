/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-30 10:27:51
 * @LastEditTime: 2025-06-08 10:12:14
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\CCF.数值积分.cpp
 * @技术宅拯救世界！！！
 */
/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-30 10:27:51
 * @LastEditTime: 2025-05-30 10:32:04
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\CCF.数值积分.cpp
 * @技术宅拯救世界！！！
 */

/* 题目描述
在了解了数值积分的基本原理后，小 P 打算用如下方法估算二次函数在[l,r]
区间的积分：

给定二次函数 f(x)=x^2+bx+c，其中两个系数 b 和 c均为整数；

对于给定区间 [l,r]（l 和 r 均为整数），选取闭区间内所有偶数坐标点：l≤x, x+2,
x+4, ⋯≤r 分别计算每个坐标点的函数值并求和，再乘以坐标点间距 2，即计算：
s=2×(f(x)+f(x+2)+f(x+4)+⋯)
s 即为小 P 估算的积分结果。

试帮助小 P 编程实现上述计算过程：对于任意给定的系数
b、c和区间 l、r，计算并输出 s。

输入格式
从标准输入读入数据。

输入仅一行，包含四个整数 b、c、l、r，含义如前文所述。

输出格式
输出到标准输出。

输出一个整数
s，表示小 P 估算的积分结果。

样例1输入
1 2 0 5
样例1输出
64
样例2输入
-20 -20 1 1000
样例2输出
324294000

全部测试数据保证 0≤l<l+2≤r≤1000 且 −20≤b,c≤20
*/
#include <iostream>

int main() {
    int b, c, l, r;
    std::cin >> b >> c >> l >> r;
    std::cout << solve(b, c, l, r) << std::endl;
    return 0;
}

int solve(int b, int c, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i += 2) {
        sum += (i * i + b * i + c);
    }
    return sum * 2;
}