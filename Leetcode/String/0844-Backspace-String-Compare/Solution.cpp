/**
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

进阶：

你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <string>

using namespace std;


class Solution {
private:
    void back(const string &s, int &index) {
        int back_count = 0;
        for (; index >= 0 && (s[index] == '#' || back_count > 0); index--) {
            if (s[index] != '#')
                back_count--;
            else
                back_count++;
        }
    }

public:
    bool backspaceCompare(string S, string T) {
        int len1 = S.size(), len2 = T.size();
        int i = len1 - 1, j = len2 - 1;
        while (true) {
            back(S, i);
            back(T, j);

            if (i < 0 || j < 0)
                break;

            if (S[i] != T[j])
                return false;
            i--;
            j--;
        }

        if (i >= 0) {
            for (; i >= 0; i--)
                if (S[i] != '#')
                    return false;
        }

        if (j >= 0) {
            for (; j >= 0; j--)
                if (T[j] != '#')
                    return false;
        }

        return true;
    }
};