class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (auto n : nums) {
            switch (n) {
                case 0:
                    zeros++;
                    break;
                case 1:
                    ones++;
                    break;
                default:
                    break;
            }
        }

        // cout << "0 : " << zeros << ", 1: " << ones << endl; 

        for (int i = 0; i < nums.size(); i++) {
            if (zeros-- > 0) {
                nums[i] = 0;
            } else {
                if (ones-- > 0) {
                    nums[i] = 1;
                } else {
                    nums[i] = 2;
                }
            }
        }
    }
};