//
// Created by cheng on 2020/6/9.
//


/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <cmath>

class Solution {
public:
    int translateNum(int num) {
        if (num < 10)
            return 1;

        int digits_num = (int) floor(log10(num)) + 1;

        int *digits = new int[digits_num];
        for (int i = digits_num - 1; i >= 0; num /= 10, i--)
            digits[i] = num % 10;

        int *dp = new int[digits_num];
        dp[0] = 1;
        dp[1] = digits[0] != 0 && (digits[0] * 10 + digits[1]) < 26 ? 2 : 1;

        for (int i = 2; i < digits_num; i++) {
            dp[i] = dp[i-1];
            if (digits[i-1] != 0 && (digits[i-1] * 10 + digits[i]) < 26)
                dp[i] += dp[i-2];
        }

        int temp = dp[digits_num - 1];
        delete [] digits;
        delete [] dp;
        return temp;
    }
};