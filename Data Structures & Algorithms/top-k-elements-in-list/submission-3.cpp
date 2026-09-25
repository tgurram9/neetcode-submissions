class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num] = 1 + count[num];
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto kv : count) {
            freq[kv.second].push_back(kv.first);
        }

        vector<int> res;
        for (int i = freq.size()-1; i > 0; i--) {
            for (int j=0; j<freq[i].size(); j++) {
                res.push_back(freq[i][j]);

                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
