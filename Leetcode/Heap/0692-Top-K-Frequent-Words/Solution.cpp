
/**
 * Given a non-empty list of words, return the k most frequent elements.
 *
 * Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
 *
 * Example 1:
 * Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
 * Output: ["i", "love"]
 * Explanation: "i" and "love" are the two most frequent words.
 *     Note that "i" comes before "love" due to a lower alphabetical order.
 * Example 2:
 * Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
 * Output: ["the", "is", "sunny", "day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
 *     with the number of occurrence being 4, 3, 2 and 1 respectively.
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Input words contain only lowercase letters.
 * Follow up:
 * Try to solve it in O(n log k) time and O(n) extra space.
 */
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
private:

    void down(vector<string> &h, int i, int end, const map<string, int> &freMap) {
        while (2 * i + 1 < end) {
            int c = 2 * i + 1;
            if (c + 1 < end && (freMap.at(h[c + 1]) > freMap.at(h[c]) || (freMap.at(h[c + 1]) == freMap.at(h[c]) && h[c+1] < h[c]) )) c++;
            if (freMap.at(h[i]) > freMap.at(h[c]) || (freMap.at(h[i]) == freMap.at(h[c]) && h[i] < h[c])) break;
            swap(h[i], h[c]);
            i = c;
        }
    }

public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        map<string, int> fre{};
        for (const string &s: words) {
            fre[s]++;
        }

        vector<string> h;
        h.reserve(fre.size());
        for (const auto &itr : fre) {
            h.push_back(itr.first);
        }

        for (int i = (h.size() - 1) / 2; i >= 0; i--) {
            down(h, i, h.size(), fre);
        }

        vector<string> res(k);
        for ( int i = 0, last = h.size() - 1; i < k; i++, last--) {
            res[i] = h[0];
            h[0] = h[last];
            down(h, 0, last, fre);
        }

        return res;
    }
};