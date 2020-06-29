
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
#include <algorithm>

using namespace std;


void down(vector<int> &h, int i, int end) {
    while (i * 2 + 1 < end) {
        int l = i * 2 + 1;
        if (l + 1 < end && h[l] > h[l + 1])
            l++;

        if (h[i] < h[l])
            break;

        swap(h[i], h[l]);
        i = l;
    }
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.begin() + k, greater<>());
        for (auto itr = nums.begin() + k; itr != nums.end(); itr++) {
            if (*itr > nums.front()) {
                nums.front() = *itr;
                down(nums, 0, k);
            }
        }
        return nums.front();
    }
};