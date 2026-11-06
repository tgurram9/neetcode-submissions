class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_size;

    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for (int n : nums) {
            pq.push(n);
            if (pq.size() > k_size) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_size) {
            pq.pop();
        }

        return pq.top();
    }
};
