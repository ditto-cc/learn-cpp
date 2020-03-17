/**
 * You are given an array of strings words and a string chars.
 * 
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * 
 * Return the sum of lengths of all good strings in words.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: words = ["cat","bt","hat","tree"], chars = "atach"
 * Output: 6
 * Explanation: 
 * The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
 * Example 2:
 * 
 * Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
 * Output: 10
 * Explanation: 
 * The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 *  
 * 
 * Note:
 * 
 * 1 <= words.length <= 1000
 * 1 <= words[i].length, chars.length <= 100
 * All strings contain lowercase English letters only.
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;


class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int table[26] = {0};
        int memo[26] = {0};
        int res = 0;

        for (char c: chars) {
            table[c-97]++;
        }

        for (string word: words) {
            memcpy(memo, table, 26);
            int len = word.size(), i = 0;
            for (i = 0; i < len; i++) {
                int index = word[i]-97;

                if (!memo[index]) break;
                memo[index]--;
            }
            if (i == len) res += len;
        }

        return res;
    }
};