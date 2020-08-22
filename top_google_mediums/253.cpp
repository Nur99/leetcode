class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue <int, vector<int>, greater<int> > p;
        // sort's code is outside your class and would have to use the syntax above.
        for(auto i: intervals){
        	if(p.size() && p.top() <= i[0]){
        		p.pop();
        	}
        	p.push(i[1]);
        }
        return p.size();
    }

    
private:
    static bool cmp(vector <int> a, vector <int> b){
        if(a[0] < b[0])return true;
        if(a[0] == b[0] && a[1] <= b[1])return true;
        return false;
    }
};

