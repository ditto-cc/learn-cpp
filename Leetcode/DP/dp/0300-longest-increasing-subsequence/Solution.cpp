/**
Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


#include <vector>
#include <algorithm>
using namespace std;

// DP
// O(N^2)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.empty()) return 0;

//         int res = 1;
//         vector<int> dp(nums.size(), 1);

//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] <= nums[j]) {
//                     continue;
//                 }
//                 dp[i] = max(dp[i], dp[j]+1);
//                 res = max(res, dp[i]);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subArray(0);

        for(int i = 0; i < nums.size(); i++) {
            int j = lower_bound(subArray.begin(), subArray.end(), nums[i]) - subArray.begin();
            if (j < subArray.size()) subArray[j] = nums[i];
            else subArray.push_back(nums[i]);
        }

        return subArray.size();
    }
};