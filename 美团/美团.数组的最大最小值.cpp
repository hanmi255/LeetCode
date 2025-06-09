/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-17 11:29:12
 * @LastEditTime: 2025-05-17 11:29:12
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\美团.数组的最大最小值.cpp
 * @技术宅拯救世界！！！
 */
/*
小美的数组询问
 * 题目内容:
    小美拿到了一个由正整数组成的数组，但其中有一些元素是未知的（用 0 来表示）。
    现在小美想知道，如果那些未知的元素在区间[l, r] 范围内随机取值的话，
    数组所有元素之和的最小值和最大值分别是多少？共有 q次询问。
 *时间限制：C/C++ 1秒，其他语言2秒
 *空间限制：C / C++ 256M，其他语言512M
 *输入描述：
    第一行输入两个正整数n,q，代表数组大小和询问次数。
    第二行输入n个整数a_i，其中如果输入的a_i为 0，那么说明a_i是未知的。
    接下来的q行，每行输入两个正整数 l,r，代表一次询问。
 *输出描述： 输出q行，每行输出两个正整数，代表所有元素之和的最小值和最大值。
 *示例1
    输入例子： 3 2 1 0 3 1 2 4 4
    输出例子： 5 6 8 8
 *例子说明：
    只有第二个元素是未知的。
    第一次询问，数组最小的和是 1 + 1 + 3 = 5，最大的和是 1 + 2 + 3 = 6。
    第二次询问，显然数组的元素和必然为 8。
*/

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int n, q;
    cin >> n >> q;

    int unknownCount = 0;
    long long knownSum = 0;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            unknownCount++;
        }
        else
        {
            knownSum += arr[i];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        long long minSum = knownSum + unknownCount * l;
        long long maxSum = knownSum + unknownCount * r;

        cout << minSum << " " << maxSum << endl;
    }
    return 0;
}