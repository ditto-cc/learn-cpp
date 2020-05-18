
/*
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

 

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int res = nums[0], lowNegative = 1;
        if (res < 0) {
            lowNegative = res;
        }

        for (size_t i = 1; i < nums.size(); i++) {
            int curMax;
            if (nums[i] == 0) {
                curMax = 0;
                lowNegative = 1;
            } else if (nums[i - 1] == 0) {
                curMax = nums[i];
                if (lowNegative == 1 && nums[i] < 0)
                    lowNegative = nums[i];
            } else {
                nums[i] *= nums[i - 1];
                if (lowNegative == 1 && nums[i] < 0)
                    lowNegative = nums[i];
                curMax = nums[i] < 0 ? nums[i] / lowNegative : nums[i];
            }
            res = max(res, curMax);
        }

        return res;
    }
};