
/**
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> c;
        combine(res, c, n, 1, k);
        return res;
    }

private:
    void combine(vector<vector<int>> &res, vector<int> &c, int n, int i, int k) {

        if (k == 0) {
            res.push_back(c);
            return;
        }

        for (; i <= n; i++) {
            c.push_back(i);
            combine(res, c, n, i + 1, k - 1);
            c.pop_back();
        }
    }
};
