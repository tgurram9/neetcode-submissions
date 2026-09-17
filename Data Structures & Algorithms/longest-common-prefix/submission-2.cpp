class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;

        for (int j=0; j<strs[0].size(); j++) {
            for (int i=0; i<strs.size()-1; i++) {
                if (!(j<strs[i].size() && j<strs[i+1].size() && strs[i][j] == strs[i+1][j])) {
                    return strs[0].substr(0, j);
                }
            }
        }

        return strs[0];
    }
};