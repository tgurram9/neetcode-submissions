class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nX = 0, numsX = 0;
        int i = 0;
        while (i < nums.size() + 1) {
            nX = nX ^ i++;
        }

        i=0;
        while (i < nums.size()) {
            numsX = numsX ^ nums[i++];
        }

        return numsX ^ nX;
    }
};
