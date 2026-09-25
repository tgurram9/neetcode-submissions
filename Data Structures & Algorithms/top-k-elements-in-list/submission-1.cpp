class Solution {
    struct Comparator {
        bool operator() (pair<int, int> &a, pair<int, int> &b) const {
            return a.second > b.second;
        }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for (auto i : nums) {
            if (!freqMap.contains(i)) {
                freqMap[i] = 1;
            } else {
                freqMap[i]++;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> freq;

        for (auto kv : freqMap) {
            freq.push(kv);

            if (freq.size() > k) {
                freq.pop();
            }
        }

        vector<int> res;

        while (!freq.empty()) {
            res.push_back(freq.top().first);
            freq.pop();
        }

        return res;
    }
};
