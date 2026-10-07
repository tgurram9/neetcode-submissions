class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;

        int r = nums.size() - 1;
        int l = 0;

        while (l < r) {
            while (l < r && nums[r] == val) {
                r--;
            }

            while (l < r && nums[l] != val) {
                l++;
            }

            cout << "l : " << l << ", r : " << r << endl;
            if (l != r) {
                nums[l] = nums[r];
                nums[r] = val;
                l++; r--;
            }
        }

        return nums[l] == val ? l : l+1;
    }
};