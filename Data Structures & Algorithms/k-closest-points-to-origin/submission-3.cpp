class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto comp = [](const vector<int>& a, const vector<int>& b) { return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]); };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> closest;

        for (auto point : points) {
            closest.push({point[0], point[1]});

            if (closest.size() > k) {
                closest.pop();
            }
        }

        vector<vector<int>> ans;
        while (closest.size() > 0) {
            ans.push_back(closest.top());
            closest.pop();
        }

        return ans;
    }
};
