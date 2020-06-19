
/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
using namespace std;

inline bool is_letter(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

class Solution {
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            for (; l < r && !is_letter(s[l]); l++);
            if (l >= r)
                break;

            for (; l < r && !is_letter(s[r]); r--);
            if (l >= r)
                break;

            if (s[l] <= '9' || s[r] <= '9') {
                if (s[l] != s[r])
                    return false;
            } else if (s[l] != s[r] && abs(s[l] - s[r]) != 32)
                return false;
        }
        return true;
    }
};