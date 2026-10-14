class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        int prod = 1;
        for (int i = n-2; i >= 0; i--) {
            prod = prod * nums[i+1];
            prefix[i] = prefix[i] * prod;
        }

        return prefix;
    }
};
