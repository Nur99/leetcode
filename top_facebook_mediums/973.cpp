class Solution {
#define mp make_pair
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        for(int i = 0; i < points.size(); i++){
            double d = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            pq.push(mp(d, i));
            if(pq.size() > K){
                pq.pop();
            }
        }
        
        while(pq.size()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }    

        return ans;
    }


private:
    priority_queue <pair <int, int> > pq;
    vector <vector <int> > ans;
};
