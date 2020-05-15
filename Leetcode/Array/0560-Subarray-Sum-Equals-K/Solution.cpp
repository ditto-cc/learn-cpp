
/*
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        int res = nums[0] == k;
        unordered_map<int, int> memo;
        memo[0]++;
        memo[nums[0]]++;
        int sum = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            sum += nums[i];
            memo[sum] ++;
            auto num = memo.find(sum - k);
            if (num != memo.end()) {
                res += num->second;
                if (k == 0)
                    res--;
            }
        }
        return res;
    }
};