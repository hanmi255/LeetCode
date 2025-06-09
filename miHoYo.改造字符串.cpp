/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-13 13:06:27
 * @LastEditTime: 2025-05-13 13:08:35
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\nan.改造字符串.cpp
 * @技术宅拯救世界！！！
 */

/*
改造字符串
 * 题目内容:
    对于给定的字符串s，将其进行k轮改造，第k轮改造的步骤如下：
    ·对于每一个大写字母，将其修改为其字母表中前面的一位字母，特别的，"A'前面一位为'Z';
    ·对于每一个小写字母，将其修改为其字母表中后面的第i位字母(i从1开始)，特别的，‘z'后面一位为'a"；
    米小游想让你输出第k轮改造后的字符串。
 * 输入描述:
    第一行输入一个长度为1≤len(s)<10^6，由大小写字母混合构成的字符串s
    第二行输入一个整数k(1≤k≤10^6)代表需要改造的轮数
 * 输出描述:
    输出第k轮改造后的字符串。
 * 样例1:
    输入
    WhilE2
    输出
    Ukloc
* 说明:
    在这个样例中：第一轮改造，"WhilE"变为"VijmD"；第二轮改造，"VijmD"变为"Ukloc"。
* 算法思想:
    1：
    ·对于大写字母，总位移量为mov1=(-k%26+26)%26
    ·对于小写字母，总位移量为mov2=(k(k+1)/2)%26
    ·遍历每个字符进行转换就好

    2：
    ·预先构建字符映射表，这样在处理长字符串时可以避免重复计算转换规则
    ·直接查表就能得到转换后的字符。
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;

    // 计算位移量
    int uppercase_shift = (-k % 26 + 26) % 26;               // 大写字母向前移动
    int lowercase_shift = ((long long)k * (k + 1) / 2) % 26; // 小写字母向后移动

    // **********解法1**********

    std::string result;
    // 处理每个字符
    for (char ch : s)
    {
        if (isupper(ch))
        {
            // 大写字母处理
            result += 'A' + (ch - 'A' + uppercase_shift) % 26;
        }
        else
        {
            // 小写字母处理
            result += 'a' + (ch - 'a' + lowercase_shift) % 26;
        }
    }

    std::cout << result << std::endl;

    return 0;
    // **********解法1**********

    // **********解法2**********

    // 构建映射表
    std::vector<char> uppercase_map(26);
    std::vector<char> lowercase_map(26);

    for (int i = 0; i < 26; i++)
    {
        uppercase_map[i] = 'A' + (i + uppercase_shift) % 26;
        lowercase_map[i] = 'a' + (i + lowercase_shift) % 26;
    }

    std::string result;
    for (auto c : s)
    {
        if (isupper(c))
        {
            result += uppercase_map[c - 'A'];
        }
        else
        {
            result += lowercase_map[c - 'a'];
        }
    }

    std::cout << result << std::endl;

    return 0;
    // **********解法2**********
}