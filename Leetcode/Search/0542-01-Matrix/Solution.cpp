
/**
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

 

Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]
 

Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    int direct[4][2] = {-1, 0, 0, -1, 0, 1, 1, 0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    visit[i][j] = true;
                    q.emplace(make_pair(i, j));
                }
            }
        }

        for (int depth = 1; !q.empty(); depth++) {
            for (int len = q.size(); len > 0; len--) {
                auto front = q.front();
                q.pop();
                for (const auto & j : direct) {
                    int nx = front.first + j[0];
                    int ny = front.second + j[1];
                    if (0 <= nx && nx < m && 0 <= ny && ny < n && !visit[nx][ny]) {
                        visit[nx][ny] = true;
                        matrix[nx][ny] = depth;
                        q.emplace(make_pair(nx, ny));
                    }
                }
            }
        }

        return matrix;
    }
};