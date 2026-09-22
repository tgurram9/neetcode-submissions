class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        
        for (auto stone : stones) {
            maxheap.push(stone);
        }

        int f = 0, s = 0, diff = 0;
        while (maxheap.size() > 1) {
            f = maxheap.top();
            maxheap.pop();
            s = maxheap.top();
            maxheap.pop();
            if (f > s) {
                maxheap.push(f-s);
            }
        }

        return maxheap.size() == 0 ? 0 : maxheap.top();
    }
};
