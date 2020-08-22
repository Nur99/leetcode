class Solution {
public:
    int stoneGameII(vector<int>& piles,
                    int start,
                    int M,
                    bool p1Turn,
                    vector<vector<vector<int>>>& cache)
    {
        if (start >= piles.size())
            return 0;
        
        if (cache[start][M][p1Turn] != -1)
            return cache[start][M][p1Turn];
        
        int maxIndex = std::min(static_cast<int>(piles.size()), start + 2 * M);
        int sum = 0;
        int ans = 0;
        
        if (p1Turn)
        {
            ans = 0;
            
            for (int i = start; i < maxIndex; ++i)
            {
                sum += piles[i];
                ans = std::max(ans, sum + stoneGameII(piles, i + 1, std::max(i - start + 1, M), false, cache));
            }
        }
        else
        {
            ans = std::numeric_limits<int>::max();
            
            for (int i = start; i < maxIndex; ++i)
            {
                ans = std::min(ans, stoneGameII(piles, i + 1, std::max(i - start + 1, M), true, cache));
            }
        }
        
        cache[start][M][p1Turn] = ans;
        return ans;
    }
    
    int stoneGameII(vector<int>& piles)
    {
        int n = piles.size();
        
        vector<vector<vector<int>>> cache(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        return stoneGameII(piles, 0, 1, true, cache);
    }
};
