class Solution {
public:
    map<int , vector<int> > mpp ;
    Solution(vector<int>& nums) {
        mpp.clear() ; 
        for(int i = 0 ; i < nums.size() ; ++i){
            mpp[nums[i]].push_back(i); 
        }
    }
    
    int pick(int target) {
        int size = mpp[target].size(); 
        int index = rand() % (size) ; 
        int ans = mpp[target][index] ; 
        return ans ; 
    }
};
