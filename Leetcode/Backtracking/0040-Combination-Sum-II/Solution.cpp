
/**
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combine;
        sort(candidates.begin(), candidates.end());

        combination(res, candidates, combine, candidates.size()-1, target);
        return res;
    }
private:
    void combination(vector<vector<int>> &res, const vector<int> &candidates, vector<int> &combine, int index, int target) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            res.push_back(combine);
            return;
        }
        
        for (int i = index; i >= 0; i--) {

            if (i < index && candidates[i] == candidates[i+1]) {
                continue;
            }

            combine.push_back(candidates[i]);

            int remain = target - candidates[i];
            combination(res, candidates, combine, i-1, remain);
            combine.pop_back();
        }
    }
};