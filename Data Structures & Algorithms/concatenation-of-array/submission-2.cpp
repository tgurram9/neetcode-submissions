class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for (int i=0; i<2; i++)
            ans.insert(ans.begin(), nums.begin(), nums.end());
        
        return ans;
    }
};