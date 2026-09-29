class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> freq;
        if (a > 0) freq.push(make_pair(a, 'a'));
        if (b > 0) freq.push(make_pair(b, 'b'));
        if (c > 0) freq.push(make_pair(c, 'c'));

        string res = "";
        while (!freq.empty()) {
            auto kv = freq.top();
            freq.pop();

            if (res.size() > 1 && res[res.size()-1] == kv.second && res[res.size()-2] == kv.second) {
                if (freq.empty()) {
                    return res;
                }

                auto kv2 = freq.top();
                freq.pop();

                res += kv2.second;
                if (--kv2.first > 0) freq.push(kv2);
            } else {
                res += kv.second;
                kv.first--;
            }

            if (kv.first > 0) freq.push(kv);
        }

        return res;
    }
};