class Solution {
public:
    vector<vector<pair<int,double>>> adj;
    vector<double> ans;
    
    void dfs(int curr, int end, double prod, vector<bool> &visited, int idx) {
        visited[curr] = true;
        if(curr == end){
            ans[idx]=prod;
            return;
        }
        for(auto it:adj[curr]) {
            if(!visited[it.first])
                dfs(it.first, end, prod*it.second, visited, idx);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        int n=eq.size();
        int c=0;
        unordered_map<string,int> id;
        
        for(int i=0; i<n; i++) {
            if(id.find(eq[i][0]) == id.end())
                id[eq[i][0]]=c++;
            if(id.find(eq[i][1]) == id.end())
                id[eq[i][1]]=c++;
        }
        adj.resize(c);
        for(int i=0; i<n; i++) {
            adj[id[eq[i][0]]].push_back({id[eq[i][1]], values[i]});
            adj[id[eq[i][1]]].push_back({id[eq[i][0]], 1/values[i]});
        }
        ans.resize(queries.size(),-1);
        for(int i=0; i<queries.size(); i++) {
            if(id.find(queries[i][0]) != id.end() && id.find(queries[i][1]) != id.end())
            {
                vector<bool> visited(c,false);
                dfs(id[queries[i][0]], id[queries[i][1]], 1, visited, i);
            }
        }
        return ans;
    }
};
