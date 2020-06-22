
/*
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。

示例 1：

输入： pattern = "abba", value = "dogcatcatdog"
输出： true
示例 2：

输入： pattern = "abba", value = "dogcatcatfish"
输出： false
示例 3：

输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false
示例 4：

输入： pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则
提示：

0 <= len(pattern) <= 1000
0 <= len(value) <= 1000
你可以假设pattern只包含字母"a"和"b"，value仅包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pattern-matching-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        if (pattern.empty())
            return value.empty();

        int p_size = pattern.size();
        int v_size = value.size();
        int p_count[2] = {0};
        int a_first = -1, b_first = -1;
        for (int i = 0; i < p_size; i++) {
            if (pattern[i] == 'a') {
                p_count[0] ++;
                if (a_first < 0)
                    a_first = i;
            } else {
                p_count[1] ++;
                if (b_first < 0)
                    b_first = i;
            }
        }

        if (value.empty())
            return p_count[0] == 0 || p_count[1] == 0;

        if (p_count[0] == 0 || p_count[1] == 0) {
            if (v_size % p_size != 0)
                return false;
            int size = v_size / p_size;
            const string &s = value.substr(0, size);
            for (int i = size; i < v_size; i += size) {
                if (s != value.substr(i, size))
                    return false;
            }
            return true;
        }

        vector<array<int, 2>> size_list;
        for (int v = v_size, i = 0; v >= 0; i++, v = v_size - p_count[1] * i) {
            if (v % p_count[0] != 0)
                continue;
            size_list.push_back(array<int, 2>{v / p_count[0], i});
        }


        int a_size, b_size;
        for (const auto &e: size_list) {
            int a_index, b_index;
            a_size = e[0], b_size = e[1];
            if (a_first == 0) {
                a_index = 0;
                b_index = b_first * a_size;
            } else {
                b_index = 0;
                a_index = a_first * b_size;
            }
            const string &a_str = value.substr(a_index, a_size);
            const string &b_str = value.substr(b_index, b_size);

            int i = 0;
            for (char c : pattern) {
                if (c == 'a') {
                    if (a_str != value.substr(i, a_size))
                        break;
                    i += a_size;
                } else {
                    if (b_str != value.substr(i, b_size))
                        break;
                    i += b_size;
                }
            }

            if (i == v_size)
                return true;
        }

        return false;
    }
};