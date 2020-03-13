#include <vector>

using namespace std;

/**
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int i = n - 2;
        for (; i >= 0 && nums[i] >= nums[i + 1]; i--);

        if (i != -1) {
            int j;
            for (j = i + 1; j < n && nums[i] < nums[j]; j++);
            swap(nums[i], nums[j - 1]);
        }

        reverse(nums, i + 1, n - 1);
    }

private:
    void reverse(vector<int> &nums, int l, int r) {
        for (; l < r; l++, r--)
            swap(nums[l], nums[r]);
    }
};