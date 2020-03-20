
/**
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * Example 2:
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <vector>

using namespace std;


class Solution {
private:
    void down(vector<int> &h, int i, int end) {
        while (2 * i + 1 < end) {
            int c = 2 * i + 1;
            if (c + 1 < end && h[c + 1] < h[c]) c++;
            if (h[i] <= h[c]) break;
            swap(h[i], h[c]);
            i = c;
        }
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        for (int i = (k - 1) / 2; i >= 0; i--) down(nums, i, k);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > nums[0]) {
                nums[0] = nums[i];
                down(nums, 0, k);
            }
        }
        return nums[0];
    }
};