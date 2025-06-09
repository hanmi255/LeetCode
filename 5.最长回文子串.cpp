/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        // 以每个字符为中心，向两边扩展
        int n = s.size();
        if (n == 0)
            return "";
        string res = "";
        for (int i = 0; i < n; i++)
        {
            string s1 = palindrome(s, i, i);     // 奇数长度的回文串
            string s2 = palindrome(s, i, i + 1); // 偶数长度的回文串
            res = res.size() >= s1.size() ? res : s1;
            res = res.size() >= s2.size() ? res : s2;
        }
        return res;
    }

    // 返回回文字符串 使用中心扩散法
    string palindrome(string s, int l, int r)
    {
        int len = s.size();
        while (l >= 0 && r < len && s[l] == s[r])
        {
            l--;
            r++;
        }

        // 循环结束时 l和r已经超出回文串的左右边界
        // 所以l+1和r-1是回文串的左右边界
        // 子串的起始位置为l+1,长度为(r-1)-(l+1)+1 = r-l-1
        return s.substr(l + 1, r - l - 1);
    }
};
// @lc code=end
