
/**
 * Given an array of integers nums, sort the array in ascending order.
 *
 *  
 *
 * Example 1:
 *
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 *
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *  
 *
 * Constraints:
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/sort-an-array
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;


class Solution {
private:
    void qSort(vector<int> & nums, int l, int r) {
        if (l >= r) return;

        int lt = l, gt = r;
        for (int i = l+1; i < gt;) {
            if (nums[l] == nums[i]) {
                i++;
            } else if (nums[l] < nums[i]) {
                swap(nums[lt+1], nums[i]);
                lt++;
                i++;
            } else {
                swap(nums[gt-1], nums[i]);
                gt--;
            }
        }
        swap(nums[l], nums[lt]);

        qSort(nums, l, lt);
        qSort(nums, gt, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        qSort(nums, 0, nums.size());
        return nums;
    }
};