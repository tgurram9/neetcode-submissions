class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int maj = nums[0];

        int i = 1;
        while (i < nums.size()) {
            if (maj == nums[i]) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    maj = nums[i];
                    count = 1;
                }
            }
            i++;
        }

        return maj;
    }
};