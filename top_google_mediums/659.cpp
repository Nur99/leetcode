class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int,int> cnt,tail;
        for(auto it:a)cnt[it]++;
        for(auto it:a)
        {
            if(!cnt[it])continue;
            cnt[it]--;
            if(tail[it-1]>0)
            {
                tail[it-1]--;
                tail[it]++;
            }
            else if(cnt[it+1] and cnt[it+2])
            {
                cnt[it+1]--;
                cnt[it+2]--;
                tail[it+2]++;
            }
            else return false;
        }
        return true;
    }
};
