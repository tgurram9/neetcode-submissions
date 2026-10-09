class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;

        unordered_map<int, int> freq;

        for (auto n : nums) {
            freq[n] += 1;
        }

        for (auto ent :freq) {
            pq.push(make_pair(ent.second, ent.first));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        int size = pq.size();
        for (int i=0; i<size; i++) {
            auto n = pq.top();
            pq.pop();
            res.push_back(n.second);
        }

        return res;
    }
};
