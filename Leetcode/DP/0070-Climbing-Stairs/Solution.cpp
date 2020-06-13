
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <array>

using namespace std;


typedef array<unsigned long long, 2> array_2;
typedef array<array<unsigned long long, 2> , 2> square_2d;

class Solution {
private:
    void multiAssign(square_2d &m1, const square_2d m2) {
        unsigned long long v00 = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
        unsigned long long v01 = m1[0][1] * m2[1][1] + m1[0][0] * m2[0][1];
        unsigned long long v10 = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
        unsigned long long v11 = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];
        m1[0][0] = v00;
        m1[0][1] = v01;
        m1[1][0] = v10;
        m1[1][1] = v11;
    }

public:
    int climbStairs(int n) {

        square_2d m{array_2{1, 1}, array_2{1, 0}};
        square_2d res{array_2{1, 0}, array_2{0, 1}};

        for (; n > 0; n >>= 1) {
            if (n & 1)
                multiAssign(res, m);
            multiAssign(m, m);
        }

        return res[0][0];
    }
};
