/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-17 11:47:31
 * @LastEditTime: 2025-05-19 19:57:52
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\美团.修改字符串的最大数量.cpp
 * @技术宅拯救世界！！！
 */
/*
小美的 MT
 * 题目内容:
    MT 是美团的缩写，因此小美很喜欢这两个字母。
    现在小美拿到了一个仅由大写字母组成字符串，她可以最多操作k次,每次可以修改任意一个字符。
    小美想知道，操作结束后最多共有多少个'M'和'T'字符？
 *时间限制：C/C++ 1秒，其他语言2秒
 *空间限制：C/C++ 256M，其他语言512M
 *输入描述：
    第一行输入两个正整数n,k，代表字符串长度和操作次数。
    第二行输入一个长度为n的、仅由大写字母组成的字符串。
 *输出描述：
 *输出操作结束后最多共有多少个'M'和'T'字符。
 *示例1
    输入例子：
    5 2
    MTUAN
 *输出例子：
    4
 *例子说明：
    修改第三个和第五个字符，形成的字符串为 MTTAM，这样共有 4 个'M'和'T'。
*/

#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
   int n, k;
   cin >> n >> k;

   string str;
   cin >> str;

   int mtCount = 0;
   for (const auto &c : str)
   {
      if (c == 'M' || c == 'T')
      {
         mtCount++;
      }
   }

   int changeable = min(k, n - mtCount);
   int maxCount = changeable + mtCount;
   cout << maxCount;
   return 0;
}
