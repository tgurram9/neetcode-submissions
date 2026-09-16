class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> angms;
        for (int i=0; i<strs.size(); i++) {
            vector<int> fingpt(26, 0);
            int idx = 0;
            while (idx < strs[i].size()) {
                fingpt[strs[i][idx] - 'a']++;
                idx++;
            }

            string str;
            for (int j=0; j<26; j++) {
                if (fingpt[j] != 0) {
                    str += string(1, (char)('a' + j)) + to_string(fingpt[j]);
                }
            }

            angms[str].emplace_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto it : angms) {
            ans.emplace_back(it.second);
        }

        return ans;
    }
};
