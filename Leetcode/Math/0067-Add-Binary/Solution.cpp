/**
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>

using namespace std;


class Solution {
private:
    const char temp[2] = {'0', '1'};

    string solution(string s, string l, int sl, int ll) {
        int carry = 0;
        for (int i = sl-1, j = ll-1; i >= 0 && j >= 0; i--, j--) {
            if (s[i] == l[j]) {
                l[j] = temp[carry];
                carry = s[i] == '1' ? 1 : 0;
            } else {
                l[j] = temp[1-carry];
            }
        }

        for (int i = ll - sl - 1; i >= 0 && carry; i--) {
            if (l[i] == '1') {
                l[i] = '0';
            } else {
                l[i] = '1';
                carry = 0;
                break;
            }
        }

        if (carry) {
            return "1"+l;
        }
        return l;
    }

public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();

        return m < n ? solution(a, b, m, n) : solution(b, a, n, m);
    }
};