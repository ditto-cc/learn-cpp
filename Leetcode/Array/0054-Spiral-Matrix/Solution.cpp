/*
 *
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;

        int iEnd = matrix.size() - 1;
        if (matrix.begin()->empty())
            return res;

        int jEnd = matrix.begin()->size() - 1;
        int iStart = 0, jStart = 0;
        while (true) {
            int i = iStart, j = jStart;
            for (; j <= jEnd; j++)
                res.push_back(matrix[i][j]);
            if (++iStart > iEnd)
                break;

            for (i++, j--; i <= iEnd; i++)
                res.push_back(matrix[i][j]);
            if (--jEnd < jStart)
                break;

            for (i--, j--; j >= jStart; j--)
                res.push_back(matrix[i][j]);
            if (--iEnd < iStart)
                break;

            for (i--, j++; i >= iStart; i--)
                res.push_back(matrix[i][j]);
            if (++jStart > jEnd)
                break;
        }

        return res;
    }
};
