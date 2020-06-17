
/*
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。

一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。

返回一对观光景点能取得的最高分。

 

示例：

输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 

提示：

2 <= A.length <= 50000
1 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-sightseeing-pair
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <vector>

using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = A[0] + A[1] - 1;
        int maxCur = A[0] - 2;
        if (A[1] - 1 > maxCur)
            maxCur = A[1] - 1;

        for (int i = 2, temp; i < A.size(); i++) {
            temp = maxCur + A[i];
            if (temp > res)
                res = temp;
            maxCur = (A[i] > maxCur ? A[i] : maxCur) - 1;
        }

        return res;
    }
};