class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string s: wordList){
            d.insert(s);
        }

        q.push(beginWord);
        d.erase(beginWord);

        while(q.size()){
            int l = q.size();
            while(l--){
                string t = q.front();
                q.pop();
                if(t == endWord){
                    return ans;
                }
                for(int i = 0; i < t.size(); i++){
                    for(char c = 'a'; c <= 'z'; c++){
                        swap(t[i], c);
                        if(d.find(t) != d.end()){
                            d.erase(t);
                            q.push(t);
                        }
                        swap(t[i], c);
                    }
                }
            }
            ans++;
        }
        return 0;
    }

private:
    unordered_set <string> d;
    queue <string> q;
    int ans = 1;
};

