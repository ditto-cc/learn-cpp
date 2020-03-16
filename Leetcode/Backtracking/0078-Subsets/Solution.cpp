
/**
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
using namespace std;

class Solution {
private:
    void subsetSolution(vector<vector<int>> &res, const vector<int> &nums, vector<int> &set, int i) {
        if (i < -1) return;

        res.push_back(set);
        for (; i >= 0; i--) {
            set.push_back(nums[i]);
            subsetSolution(res, nums, set, i - 1);
            set.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> set;
        subsetSolution(res, nums, set, nums.size() - 1);
        return res;
    }
};