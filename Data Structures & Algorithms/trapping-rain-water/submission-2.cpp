class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int lh = height[l];
        int rh = height[r];

        int res = 0;
        while (l < r) {
            if (lh <= rh) {
                l++;
                lh = max(height[l], lh);
                res += (lh - height[l]);
            } else {
                r--;
                rh = max(height[r], rh);
                res += (rh - height[r]);
            }
        }

        return res;
    }
};
