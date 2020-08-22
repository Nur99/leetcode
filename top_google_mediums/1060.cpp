class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int range = nums.size()-1;
        int missing = nums[range] - (nums[0] + range);
        
        //outside the array boundary
        if (k > missing) return nums[range] + (k - missing);
        
        //inside the array boundary
        missing = k;
        for (int diff = 0, i = 1; i <= range; i++) {
            diff = nums[i] - nums[i-1] - 1;
            if (diff >= missing) return nums[i-1] + missing;
            missing -= diff;
        }//for
        
        return 0;
    }
};
