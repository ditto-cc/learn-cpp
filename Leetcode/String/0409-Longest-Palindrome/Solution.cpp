
/**
 * Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * Example:
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 */
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int memo[52] = {0};
        for (char c: s) {
            if (65 <= c && c <= 90) {
                memo[c-65]++;
            } else if (97 <= c && c <= 122) {
                memo[c-71]++;
            }
        }

        int odd = 0, res = 0;
        for (int n: memo) {
            res += n - (n & 1);
            odd |= n & 1;
        }
        return res + odd;
    }
};