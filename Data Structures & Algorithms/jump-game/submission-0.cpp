class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> canReach(n, false);
        canReach[0] = true;

        for (int i = 0; i < n; i++) {
            if (!canReach[i]) {
                return false;
            }
            if (nums[i] + i >= n - 1) {
                return true;
            }
            for (int step = 1; step <= nums[i]; step++) {
                canReach[i + step] = true;
            }
        }
        return true;
    }
};