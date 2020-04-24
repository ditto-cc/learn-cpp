
/*
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;


class Solution {
private:
    vector<int> temp;
    int merge(vector<int> &nums, int l, int mid, int r) {
        int res = 0;

        for (int k = l, i = l, j = mid; k < r; k++) {
            if (j >= r) {
                temp[k] = nums[i];
                i++;
            } else if (i >= mid || nums[i] <= nums[j]) {
                temp[k] = nums[j];
                j++;
            } else {
                res += r - j;
                temp[k] = nums[i];
                i++;
            }
        }

        for (int i = l; i < r; i++)
            nums[i] = temp[i];

        return res;
    }

    int mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r - 1) return 0;
        int mid = l + (r - l) / 2;
        int res = mergeSort(nums, l, mid);
        res += mergeSort(nums, mid, r);
        res += merge(nums, l, mid, r);
        return res;
    }

public:
    int reversePairs(vector<int> &nums) {
        temp = vector<int>(nums.size(), 0);
        return mergeSort(nums, 0, nums.size());
    }
};