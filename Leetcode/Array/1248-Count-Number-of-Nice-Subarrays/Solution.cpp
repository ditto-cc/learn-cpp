
/*
 * 给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

 

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16
 

提示：

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-nice-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
//        int n = nums.size();
//        int res = 0;
//        vector<int> odd;
//
//        odd.push_back(-1);
//        for (int i = 0; i < n; i++)
//            if (nums[i] & 1)
//                odd.push_back(i);
//
//        odd.push_back(nums.size());
//
//        for (int l = 1, r = k; r < odd.size() - 1; l++, r++) {
//            res += (odd[l] - odd[l-1]) * (odd[r+1] - odd[r]);
//        }
//        return res;

        int res = 0;
        vector<int> counter(nums.size()+1, 0);
        counter[0] = 1;
        int odd = 0;
        for (int num : nums) {
            odd += num & 1;
            res += odd >= k ? counter[odd-k] : 0;
            counter[odd]++;
        }
        return res;
    }
};
