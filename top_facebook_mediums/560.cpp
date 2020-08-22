class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum == K){
                ans++;
            }
            if(dp[sum - K]){
                ans += dp[sum - K];
            }
            dp[sum]++;
        }

        return ans;
    }

private:
    int sum = 0, ans = 0;
    unordered_map <int, int> dp;
};

