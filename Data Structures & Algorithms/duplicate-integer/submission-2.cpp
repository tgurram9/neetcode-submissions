#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();

        if (len > 0)
            sort(nums.begin(), nums.end());

        for (int i=0; i < len-1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }

        return false;
    }
};