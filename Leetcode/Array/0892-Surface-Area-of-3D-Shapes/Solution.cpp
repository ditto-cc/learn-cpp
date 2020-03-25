/**
 * On a N * N grid, we place some 1 * 1 * 1 cubes.
 *
 * Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).
 *
 * Return the total surface area of the resulting shapes.
 *
 *  
 *
 * Example 1:
 *
 * Input: [[2]]
 * Output: 10
 * Example 2:
 *
 * Input: [[1,2],[3,4]]
 * Output: 34
 * Example 3:
 *
 * Input: [[1,0],[0,2]]
 * Output: 16
 * Example 4:
 *
 * Input: [[1,1,1],[1,0,1],[1,1,1]]
 * Output: 32
 * Example 5:
 *
 * Input: [[2,2,2],[2,1,2],[2,2,2]]
 * Output: 46
 *  
 *
 * Note:
 *
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/surface-area-of-3d-shapes
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        size_t n = grid.size() - 1;
        if (n == -1) return 0;
        if (n == 0) return grid[0][0] * 4 + 2;

        int res = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (!grid[i][j]) continue;

                res += (grid[i][j] * 4) + 2;
                if (i > 0) res -= 2 * min(grid[i][j], grid[i-1][j]);
                if (j > 0) res -= 2 * min(grid[i][j], grid[i][j-1]);
            }
        }

        return res;
    }
};