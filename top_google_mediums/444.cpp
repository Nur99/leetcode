class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        auto n = org.size();
        vector<int> m(n + 1);
        vector<bool> linked(n);
        for (auto i = 0; i < org.size(); ++i)
            m[org[i]] = i;
        for (auto &seq: seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                if (seq[i] < 1 || seq[i] > n)
                    return false;
                auto id2 = m[seq[i]];
                if (id2 == n - 1)
                     linked[id2] = true; 
                if (i != 0) {
                    auto id1 = m[seq[i - 1]];
                    if (id1 >= id2)
                        return false;
                    if (id1 + 1 == id2)
                        linked[id1] = true;
                }
            }
        } 
        return count(begin(linked), end(linked), true) == n;
    }
};

