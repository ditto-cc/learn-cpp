/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 * Example 1:
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * Example 2:
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 */
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 2 || numRows <= 1) return s;

        string res;
        int pace = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {

            for (int j = i; j < s.size(); j+=pace) {
                res += s[j];
                int index = j+pace-2*i;
                if (i > 0 && index < s.size() && j != index)
                    res += s[index];
            }
        }

        return res;
    }
};