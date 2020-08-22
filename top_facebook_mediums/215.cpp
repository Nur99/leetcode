class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i: nums){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(pq.size()){
            pq_.push(pq.top());
            pq.pop();
        }

        while(k--){
            ans = pq_.top();
            pq_.pop();
        }

        return ans;
    }

private:
    priority_queue <int, vector <int>, greater <int>> pq;
    priority_queue <int> pq_;
    int ans = 0;
};

