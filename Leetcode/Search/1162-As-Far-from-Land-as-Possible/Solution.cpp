/**
 * Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.
 *
 * The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 *
 * If no land or water exists in the grid, return -1.
 *
 *  
 *
 * Example 1:
 *
 *
 *
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation:
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * Example 2:
 *
 *
 *
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation:
 * The cell (2, 2) is as far as possible from all the land with distance 4.
 *  
 *
 * Note:
 *
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 */
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        deque<int> q;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push_back(i * n + j);
            }
        }

        if (q.empty() || q.size() == n * n) return -1;

        int res = -1;
        for (int levelNum = q.size(); levelNum > 0; levelNum = q.size()) {
            for (int i = 0; i < levelNum; i++) {
                int x = q[i]/n, y = q[i]%n;
                if (x-1 >= 0 && grid[x-1][y] == 0) {
                    grid[x-1][y] = 1;
                    q.push_back(q[i]-n);
                }
                if (x+1 < n && grid[x+1][y] == 0) {
                    grid[x+1][y]=1;
                    q.push_back(q[i]+n);
                }
                if (y-1 >= 0 && grid[x][y-1] == 0) {
                    grid[x][y-1] = 1;
                    q.push_back(q[i]-1);
                }
                if (y+1 < n && grid[x][y+1] == 0) {
                    grid[x][y+1] = 1;
                    q.push_back(q[i]+1);
                }
            }
            q.erase(q.begin(), q.begin()+levelNum);
            res++;
        }
        
        return res;
    }
};