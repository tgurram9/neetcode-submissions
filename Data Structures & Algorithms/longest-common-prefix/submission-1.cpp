class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {       
        string ans;
        bool flag = false;
        int j = 0; // char index
        while (j < strs[0].size()) { // letters
            char ptr = strs[0][j]; // b
            flag = true;

            for (int i=1; i<strs.size(); i++) { // words
                if (strs[i][j] != ptr) {
                    flag = false;
                    break;
                }
            }

            if (!flag) break;
            ans += ptr;
            j++;
        }

        return ans;
    }
};