class Solution {
#define mp make_pair
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size()){
            return 0;
        }
        n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                check(i - 1, j, i, j, matrix);
                check(i + 1, j, i, j, matrix);
                check(i, j - 1, i, j, matrix);
                check(i, j + 1, i, j, matrix);
            }
        }    


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!used[mp(i, j)]){
                    dfs(i, j);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, deg[mp(i, j)]);
            }
        }

        return ans;
    }

private:
    map <pair <int, int>, vector <pair <int, int> > > v;
    map <pair <int, int>, bool> used;
    map <pair <int, int>, int> deg;
    int n, m, ans = 0;

    void check(int x2, int y2, int x, int y, vector<vector<int>>& matrix){
        if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && matrix[x][y] > matrix[x2][y2]){
            v[mp(x, y)].push_back(mp(x2, y2));
        }
    }

    void dfs(int x, int y){
        used[mp(x, y)] = 1;

        for(auto next: v[mp(x, y)]){
            if(!used[mp(next.first, next.second)]){
                dfs(next.first, next.second);
            }
            deg[mp(x, y)] = max(deg[mp(x, y)], deg[mp(next.first, next.second)] + 1);
        }
        if(v[mp(x, y)].size() == 0){
            deg[mp(x, y)] = 1;
        }
    }
};

