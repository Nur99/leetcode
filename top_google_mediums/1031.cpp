class Solution {
public:
    void f(vector<int>&ll, vector<int>& lr, int L, const vector<int>& sum) {
        ll[L-1] = sum[L-1];
        for(int i = L;i<sum.size();i++) {
            ll[i] = sum[i] - sum[i-L];
            ll[i] = max(ll[i],ll[i-1]);
        }
        lr[sum.size()-L] = sum.back() - ((sum.size()>L)?sum[sum.size()-L-1]:0);
        for(int i = sum.size()-L-1;i>=0;i--){
            lr[i] = sum[i+L-1] - ((i-1>=0)?sum[i-1]:0);
            lr[i] = max(lr[i],lr[i+1]);
        }
    } 
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        vector<int> sum(A.size(),0);
        sum[0] = A[0];
        for(int i = 1;i < A.size();i++) {
            sum[i] = sum[i-1] + A[i];
        }
        vector<int> ll(A.size(),0), lr(A.size(),0),ml(A.size(),0),mr(A.size(),0);
        f(ll,lr,L,sum);
        f(ml,mr,M,sum);
        int ret = 0;
        for(int i = 0;i<A.size()-1;i++) {
            ret = max(ret,ll[i] + mr[i+1]);
            ret = max(ret,ml[i] + lr[i+1]);
        }
        return ret; 
        
       
    }
};
