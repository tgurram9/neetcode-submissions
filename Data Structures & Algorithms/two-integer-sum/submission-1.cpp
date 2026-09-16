class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pos;

        pos[nums[0]] = 0;
        
        for (int i=1; i<nums.size(); i++) {
            if (pos.contains(target - nums[i])) {
                return {pos[target - nums[i]], i};
            }
        
            pos[nums[i]] = i;
        }

        // 4 - 0
        // 5 - 1
        // 
    }
};
