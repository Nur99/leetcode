class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        
        int N = S.length();
        vector<int> match(N, -1);

        for (int i = 0; i < indexes.size(); ++i) {
            int ix = indexes[i];
            if (S.substr(ix, sources[i].size()) == (sources[i]))
                match[ix] = i;
        }

        string ans;
        int ix = 0;
        while (ix < N) {
            if (match[ix] >= 0) {
                ans += targets[match[ix]];
                ix += sources[match[ix]].length();
            } else {
                ans += S[ix++];
            }
        }
        return ans;
    }
};
