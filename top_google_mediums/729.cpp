class MyCalendar {
public:
    vector<pair<int,int>>a;     // will maintin it in sorted manner.
    MyCalendar() {
        a.clear();
    }
    
    bool book(int start, int end) {
        pair<int,int>p={start,end};
        if(a.size() == 0){
            a.push_back(p);
            return true;
        }
        auto it =lower_bound(a.begin(),a.end(),p);
        int pos=it-a.begin();
        // check is there any overlapping between pair and its potential neighbor in sorted array.
        if(checkOverlapping(a,pos-1, p) or checkOverlapping(a,pos, p) or checkOverlapping(a,pos+1, p)) {
            return false;
        }
        a.insert(it,p);
        return true;
    }
    /*Check overlapping between given pair and pair at ith index*/
    private: bool checkOverlapping(vector<pair<int,int>> &a,int i, pair<int,int> &p) {
        if(i<0 or i>=a.size())
            return false;
        if(a[i].first <= p.first && a[i].second > p.first)
            return true;
        if(p.first <= a[i].first && p.second > a[i].first)
            return true;
        return false;
    }
};


