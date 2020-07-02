
/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

 

示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
 

提示：
你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;

class Solution {
private:
    int countLower(const vector<vector<int>> &matrix, int val, int n) {
        int count = 0;
        for (int i = n - 1, j = 0; i >= 0;) {
            if (j == n || matrix[i][j] > val) {
                count += j;
                i--;
            } else if (matrix[i][j] <= val) {
                j++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int count = countLower(matrix, mid, n);
            if (count >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};