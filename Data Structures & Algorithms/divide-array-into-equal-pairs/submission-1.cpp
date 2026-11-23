class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> counts;
        for (auto num : nums) {
            counts[num]++;
        }

        for (auto [k, v] : counts) {
            if (v % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};