class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);

        for(string s: words){
            d.insert(s);
            m[s] = 1;
        }

        for(string s: words){
            for(int i = 0; i < s.size(); i++){
                string t = "";
                for(int j = 0; j < s.size(); j++){
                    if(j != i){
                        t += s[j];
                    }
                }
                if(d.find(t) != d.end()){
                    m[t] = max(m[t], m[s] + 1);
                }
            }
        }    

        for(auto i: m){
            ans = max(ans, i.second);
        }
        return ans;
    }

private:
    unordered_map <string, int> m;
    unordered_set <string> d;
    int ans = 0;
    static bool cmp(string a, string b){
        return a.size() > b.size();
    }

};

