class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        multiset<int>s;
        for(int i=0;i<hand.size();i++){
            s.insert(hand[i]);
        }
        while(s.size()!=0){
            int a=W-1;
            int b=*(s.begin());
            s.erase(s.begin());
            while(a--){
                if(s.find(b+1)!=s.end()){
                    b++;
                    s.erase(s.find(b));
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
