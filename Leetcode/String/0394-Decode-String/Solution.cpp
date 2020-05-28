
/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        size_t size = s.size();
        string res;
        for (size_t i = 0; i < size;)
        {
            if (s[i] >= '1' && s[i] <= '9')
            {
                size_t j = i + 1, sum = 1, k = s[i] - '0';
                for (; j < size && s[j] >= '0' && s[j] <= '9'; j++)
                {
                    k *= 10;
                    k += s[j] - '0';
                }

                i = j;
                for (j++; sum > 0 && j < size; j++)
                {
                    if (s[j] == '[')
                        sum++;
                    else if (s[j] == ']')
                        sum--;
                }
                string temp = decodeString(s.substr(i + 1, j - i - 2));
                for (; k > 0; k--)
                    res.append(temp);
                i = j;
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};