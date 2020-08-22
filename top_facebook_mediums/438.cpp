class Solution {
    bool isAnagrams(vector<int> count) {
        for (int i = 0; i < count.size(); ++i) {
            if (count[i] != 0) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string_view s, string_view p) {
        vector<int> indexes;
        if (p.length() > s.length()) return indexes;
        vector<int> count('z' - 'a' + 1, 0);
        for (int i = 0; i < p.length(); ++i) {
            count[p[i] - 'a']++;
        }
        for (int i = 0; i < p.length(); ++i) {
            count[s[i] - 'a']--;
        }
        if (isAnagrams(count)) {
            indexes.push_back(0);
        } 
        for (int i = 0; i < s.length(); ++i) {
            if (i + p.size() < s.length()) {
                count[s[i] - 'a']++;
                count[s[i + p.size()] - 'a']--;
                if (isAnagrams(count)) {
                    indexes.push_back(i + 1); 
                } 
            } 
        }
        return indexes;
    }
};
