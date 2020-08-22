class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string>s(deadends.begin(), deadends.end());
        unordered_set<string>visited;
        
        queue<string>q;
        q.push("0000");
        
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                
                if (s.find(str) != s.end() || visited.find(str) != visited.end())
                    continue;
                
                if (str == target)
                    return steps;
                
                visited.insert(str);
                for (int j = 0; j < str.length(); j++) {
                    string up = str;
                    up[j] = up[j] == '9' ? '0' : up[j] + 1;
                    q.push(up);
                    
                    string down = str;
                    down[j] = down[j] == '0' ? '9' : down[j] - 1;
                    q.push(down);
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};
