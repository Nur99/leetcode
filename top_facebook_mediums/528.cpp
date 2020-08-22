class Solution {
public:
    set<pair<double, int>> P;
    default_random_engine gen;
    Solution(vector<int>& w) {
        int s = 0;
        for (int ww: w) s+=ww;
        
        double curr = 0;
        for (int i = 0; i < w.size(); i++){
            curr += (double) w[i]/s;
            P.insert({curr, i});
        }
    }
    
    int pickIndex() {
        double rand = generate_canonical<double, 10> (gen);
        return P.lower_bound({rand, -1})->second;
    }
};

