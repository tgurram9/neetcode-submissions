class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> counts;

        int i = 0;
        while (i < s.length()) counts[s[i++]]++;

        i = 0;
        while (i < t.length()) {
            if (!counts.contains(t[i]) || counts[t[i]] == 0)
                return false;
            counts[t[i++]]--;
        }

        return true;
    }
};
