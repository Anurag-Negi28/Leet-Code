class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int ans = 0;
        // Create max-heap to store the elements.
        priority_queue<int> pq;
        for (auto& i : nums) {
            pq.push(i);
        }

        while (k--) {
            // Add the maxElement in ans and push it's one-third value in the
            // priority queue.
            int maxElement = pq.top();
            ans += maxElement;
            pq.pop();
            pq.push(ceil(maxElement / 3.0));
        }
        return ans;
    }
};