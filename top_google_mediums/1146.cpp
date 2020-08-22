class SnapshotArray {
    struct Val{
        int val;
        int snap_id;
        vector<pair<int, int>> valSnap;
        Val(int n_val, int n_snap_id, vector<pair<int, int>> n_my_vect) : 
        val(n_val), snap_id(n_snap_id), valSnap(n_my_vect) { }
    };
    
public:
    vector<Val> myVector;
    int countSnap = 0;
    unordered_set <int> changes;
    SnapshotArray(int length) {
        for (int i = 0; i< length; ++i) {
            vector<pair<int, int>> valSnap;
            valSnap.push_back(make_pair(0, 0));
            Val val = Val(0, 0, valSnap);
            myVector.push_back(val);
        }
    }
    
    void set(int index, int val) {
        changes.insert(index);
        myVector[index].val = val;
    }
    
    int snap() {
        for(auto it : changes) {
            myVector[it].snap_id = countSnap;
            myVector[it].valSnap.push_back(make_pair(myVector[it].val, myVector[it].snap_id));    
        }
        changes.clear();
        return countSnap++;
    }
    
    int get(int index, int snap_id) {
        int res = -1;
        for (int i = myVector[index].valSnap.size() - 1; i >= 0; --i) {
            if (myVector[index].valSnap[i].second <= snap_id) {
                return myVector[index].valSnap[i].first;
            }
        }
        return res;
    }
};
