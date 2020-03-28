/**
 * In a deck of cards, each card has an integer written on it.
 *
 * Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:
 *
 * Each group has exactly X cards.
 * All the cards in each group have the same integer.
 *
 *
 * Example 1:
 *
 * Input: deck = [1,2,3,4,4,3,2,1]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
 * Example 2:
 *
 * Input: deck = [1,1,1,2,2,2,3,3]
 * Output: false´
 * Explanation: No possible partition.
 * Example 3:
 *
 * Input: deck = [1]
 * Output: false
 * Explanation: No possible partition.
 * Example 4:
 *
 * Input: deck = [1,1]
 * Output: true
 * Explanation: Possible partition [1,1].
 * Example 5:
 *
 * Input: deck = [1,1,2,2,2,2]
 * Output: true
 * Explanation: Possible partition [1,1],[2,2],[2,2].
 *
 *
 * Constraints:
 *
 * 1 <= deck.length <= 10^4
 * 0 <= deck[i] < 10^4
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        if (a == b) {
            return a;
        }

        int r1 = a & 1, r2 = b & 1;
        if (r1 == 1 && r2 == 1) {
            return a < b ? gcd(b - a, a) : gcd(a - b, b);
        } else if (r1 == 0 && r2 == 0) {
            return gcd(a >> 1, b >> 1) << 1;
        } else if (r1 == 1 && r2 == 0) {
            return gcd(a, b >> 1);
        } else {
            return gcd(a >> 1, b);
        }
    }

public:
    bool hasGroupsSizeX(vector<int> &deck) {
        unordered_map<int, int> m{};
        for (const int &e: deck) {
            m[e]++;
        }

        int res = 0;
        for (const auto &itr: m) {
            if (itr.second == 1 || res == 1) {
                return false;
            }

            if (res == 0) {
                res = itr.second;
            } else {
                res = gcd(res, itr.second);
            }
        }

        return res >= 2;
    }
};