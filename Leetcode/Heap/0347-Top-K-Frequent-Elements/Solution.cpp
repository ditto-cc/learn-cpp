/**
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 * Note:
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {

private:
    void down(vector<int> &h, int i, int end, const unordered_map<int, int> &freMap) {
        while (2*i+1<end) {
            int c = 2*i+1;
            if (c+1<end&&freMap.at(h[c+1])<freMap.at(h[c])) c++;
            if (freMap.at(h[i]) <= freMap.at(h[c])) break;
            swap(h[i], h[c]);
            i = c;
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) return vector<int>(0);

        unordered_map<int, int> freMap(0);
        for (int e: nums) {
            auto itr = freMap.find(e);
            if (itr != freMap.end()) itr->second++;
            else freMap.insert(make_pair(e, 1));
        }

        vector<int> h;
        h.reserve(freMap.size());
        for (auto & itr : freMap) {
            h.push_back(itr.first);
        }

        for (int i = (k - 1) / 2; i >= 0; i--) {
            down(h, i, k, freMap);
        }

        for (int i = k; i < h.size(); i++) {
            if (freMap.at(h[i]) > freMap.at(h[0])) {
                h[0] = h[i];
                down(h, 0, k, freMap);
            }
        }

        return vector<int>(h.begin(), h.begin()+k);
    }
};