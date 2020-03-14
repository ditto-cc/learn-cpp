/**
 * 
 * Given an unsorted array of integers, find the number of longest increasing subsequence.
 * 
 * Example 1:
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
 * Example 2:
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 * Note: Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), count(nums.size(), 1);
        int longest = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) {
                    continue;
                }

                if (dp[j] >= dp[i]) {
                    count[i] = count[j];
                    dp[i] = 1 + dp[j];
                    longest = max(longest, dp[i]);
                } else if (1 + dp[j] == dp[i]) {
                    count[i] += count[j];
                }
            }
        }

        int res = 0;
        for (int i = 0; i < count.size(); i++) {
            if (dp[i] == longest) {
                res += count[i];
            }
        }
        return res;
    }
};