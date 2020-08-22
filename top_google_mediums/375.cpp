class Solution {
    
    vector< vector<int>> dp;
public:
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1, -1));
        return f(1, n);
    }
    
    int f(int l , int r) {
        
        if(l>=r)return 0;
        
        if(~dp[l][r])return dp[l][r];
        
        dp[l][r] = INT_MAX;
        for(int i = l; i <=r; i++)
            dp[l][r] = min(dp[l][r], i + max(f(l, i-1), f(i+1, r) ));
        
        return dp[l][r];
    }
};
