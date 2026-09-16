class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> uniq;
        auto it = nums.begin();

        while (it != nums.end()) {
            if (uniq.contains(*it)){
                return true;
            }
            uniq.insert(*it++);
        }

        return false;
    }
};