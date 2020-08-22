const int INF=1e9+5;
class Solution {
public:
    int minSumOfLengths(vector<int>& A, int K) {
        const int n = A.size();
        int sum = 0, ans=INF;
        map<int, int>hm;
        vector<int>dp(n+1);
        hm[0] = -1;
        for(int i = 0;i<n;i++){
            sum+=A[i];
            
            dp[i] = i>0?dp[i-1]:INF;
            if(hm.find(sum-K) != hm.end()){
                int l = i-hm[sum-K];
                ans=min(ans, l + (i>=l?dp[i-l]: INF) );
                dp[i] = min(dp[i], l);
            }
            
            hm[sum] = i;
        }
        
        if(ans==INF) return -1;
        return ans;
        
    }
};
