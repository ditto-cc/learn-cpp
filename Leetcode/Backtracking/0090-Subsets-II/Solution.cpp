/**
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void
    solution(vector<vector<int>> &res, const vector<int> &nums, vector<int> &set, vector<bool> visit, int i, int n) {
        if (i > n) return;

        res.push_back(set);

        for (; i < n; i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])) continue;

            visit[i] = true;
            set.push_back(nums[i]);
            solution(res, nums, set, i + 1, n);
            visit[i] = false;
            set.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> set;
        vector<bool> visit = vector<bool>(nums.size(), false);

        sort(nums.begin(), nums.end());
        solution(res, nums, set, 0, nums.size());

        return res;
    }
};