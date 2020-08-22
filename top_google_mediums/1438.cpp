class Solution {
public:
    multiset<int> S;
    bool IsOK(int num, int limit) {
            return  abs(num - *S.begin()) <= limit && 
                    abs(num - *S.crbegin()) <= limit; 
    }
    int longestSubarray(vector<int>& nums, int limit) {
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!S.empty() && j < i && !IsOK(nums[i], limit)) {
                S.erase(S.find(nums[j]));
                j++;
            }
            S.insert(nums[i]);
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
