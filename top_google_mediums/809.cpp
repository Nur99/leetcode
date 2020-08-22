class Solution {
public:
    string getCounts(string s) {
        string res;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(j < s.size() and s[i] == s[j]) j++;
            res += s[i] + to_string(j - i);
            i = j;
        }
        return res;
    }
    bool isValid(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() and j < t.size())
        {
            char first = s[i], second = t[j];
            if(first != second) return false;
            i++; j++;
            int num1 = 0, num2 = 0;
            while(i < s.size() and isdigit(s[i])) {
                num1 = num1*10 + s[i] - '0';
                i++;
            }
            while(j < t.size() and isdigit(t[j])) {
                num2 = num2*10 + t[j] - '0';
                j++;
            }
            if(num1 == num2) continue;
            if(num1 < num2 or (num1 < 3))
                return false;
        }
        return i == s.size() and j == t.size();
    }
    int expressiveWords(string s, vector<string>& words) {
        string mod  = getCounts(s);
        int res = 0;
        for(auto &word : words) {
            if(isValid(mod, getCounts(word)))
                res++;
        }
        return res;
    }
};

