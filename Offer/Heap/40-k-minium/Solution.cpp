
/**
 * 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr = [3,2,1], k = 2
 * 输出：[1,2] 或者 [2,1]
 * 示例 2：
 *
 * 输入：arr = [0,1,2,1], k = 1
 * 输出：[0]
 *
 *
 * 限制：
 *
 * 0 <= k <= arr.length <= 10000
 * 0 <= arr[i] <= 10000
 */
#include <vector>
using namespace std;

class Solution {
private:
    void down(vector<int> &data, int i, int end) {
        while (2*i+1 < end) {
            int c = 2*i+1;
            if (c + 1 < end && data[c] < data[c+1]) c++;
            if (data[i] >= data[c]) break;
            swap(data[i], data[c]);
            i = c;
        }
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(arr.begin(), arr.begin()+k);
        if (k == 0) {
            return res;
        }

        for (int i = (k - 1) / 2; i >= 0; i--) down(res, i, k);
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < res[0]) {
                res[0] = arr[i];
                down(res, 0, k);
            }
        }

        return res;
    }
};