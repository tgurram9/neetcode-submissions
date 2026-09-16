#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> comp;
        comp[nums[0]] = 0;

        for (int i=1; i<nums.size(); i++) {
            if (comp.contains(target - nums[i])) {
                return {comp[target-nums[i]], i};
            } else {
                comp[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
