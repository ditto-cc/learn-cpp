
/**
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> path;
        vector<bool> visit(nums.size(), false);

        sort(nums.begin(), nums.end());

        genPermute(res, path, nums, visit, nums.size());
        return res;
    }

private:
    void genPermute(vector<vector<int>> &res, vector<int> &path, const vector<int> &nums, vector<bool> &visit, int remain) {
        if (remain == 0) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]))
                continue;

            visit[i] = true;
            path.push_back(nums[i]);
            genPermute(res, path, nums, visit, remain - 1);
            visit[i] = false;
            path.pop_back();
        }
    }
};