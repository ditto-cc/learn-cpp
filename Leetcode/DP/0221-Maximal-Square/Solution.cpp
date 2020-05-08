
/*
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        size_t m = matrix.size();
        if (m == 0) {
            return 0;
        }
        size_t n = matrix[0].size();
        if (n == 0) {
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == '1') {
                res = 1;
                dp[0][i] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                res = 1;
                dp[i][0] = 1;
            }
        }

        if (m == 1 || n == 1) {
            return res;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                    res = max(res, dp[i][j] * dp[i][j]);
                }
            }
        }

        return res;
    }
};