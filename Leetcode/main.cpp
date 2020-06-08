#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        vector<int> counter(nums.size()+1, 0);
        counter[0] = 1;
        int odd = 0;
        for (int num : nums) {
            odd += num & 1;
            res += odd >= k ? counter[odd-k] : 0;
            counter[odd]++;
        }
        return res;
    }
};


int main() {

    auto s = new Solution();
    vector<int> arr({1,1,2,1,1});
    cout << s->numberOfSubarrays(arr, 3);

    return 0;
}