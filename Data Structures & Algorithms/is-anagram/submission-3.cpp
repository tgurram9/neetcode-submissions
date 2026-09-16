#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counter;

        for (char ch : s) {
            if (counter.contains(ch)) {
                counter[ch]++;
            } else {
                counter[ch] = 1;
            }
        }

        
        for (char ch : t) {
            if (counter.contains(ch) && counter[ch] > 0) {
                counter[ch]--;
            } else {
                return false;
            }
        }

        for (auto kv : counter) {
            if (kv.second != 0) return false;
        }

        return true;
    }
};
