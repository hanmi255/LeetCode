/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-13 13:25:01
 * @LastEditTime: 2025-05-13 15:06:15
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\miHoYo.删除字符.cpp
 * @技术宅拯救世界！！！
 */

/*
删除字符
 * 题目内容:
    公司里有两个字符串，分别是s和t。由于数据安全的原因，字符串t不允许作为s的子串存在。
    为了满足数据规范，米小游需要按照一定的顺序删除字符串s中的一些字符，确保s中不再包含t。
    注意删除字符si后，不会自动将前后字符串合并，你可以认为使用一个空白字符代替si。
    米小游想知道，在保证s不包含t的前提下，她最少需要删除多少个字符？
    删除顺序可以描述为一个排列，ai表示删除sai字符。
* 输入描述:
    第一行输入两个整数n和m，表示字符串s和t的长度。
    第二行输入一个长度为n的字符串，仅包含小写字母。
    第三行输入一个长度为m的字符串，仅包含小写字母。
    第四行输入一个长度为n的排列，表示第i次删除sai字符。
    1≤n≤10^5
    1≤m≤50
    1≤ai<n
* 输出描述:
    输出一个整数，表示最少需要删除的字符个数。
* 样例1:
    输入
    5 2
    ababa
    ab
    3 2 5 4 1
    输出
    2
* 说明:
    第一次删除S3，s变为ab(a)ba。
    第二次删除S2，s变为a(ba)ba。
    此时s不包含t，最少需要删除2个字符。
* 算法思想:
    1. 遍历字符串s，判断s是否包含t
    2. 如果包含，则删除s中包含t的第一个字符，并继续判断s是否包含t
    3. 如果不包含，则返回s的长度
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool containSubString(const string &s, const string &t)
{

    int n = s.length();
    int m = t.length();

    for (int i = 0; i <= n - m; ++i)
    {
        bool found = true;
        for (int j = 0; j < m; ++j)
        {
            // 如果当前位置是空格或字符不匹配，则不是有效的子串
            if (s[i + j] == ' ' || s[i + j] != t[j])
            {
                found = false;
                break;
            }
        }
        if (found)
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    string current = s;
    int deletCount = 0;

    for (int i = 0; i < n; i++)
    {
        // 删除字符(用空格代替)
        current[nums[i] - 1] = ' ';
        deletCount++;

        if (!containSubString(current, t))
        {
            break;
        }
    }

    cout << deletCount << endl;
    return 0;
}