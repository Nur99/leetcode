class Solution {
public:
    int minKnightMoves(int x, int y) {
        if (x==0 && y==0)
        {
            return 0;
        }
        queue<pair<pair<int,int>,int>>s;
        s.push(make_pair(make_pair(0,0),0));
        int one[] = {2,-2,2,-2,1,-1,1,-1};
        int sec[] = {1,1,-1,-1,2,2,-2,-2};
        int a = 0,b = 0, d= 0;
        int mat[601][601];
		
        for (int i=0;i<601;i++)
        {
            for (int j=0;j<601;j++)
            {
                mat[i][j] = 0;
            }
        }
        while(!s.empty())
        {
            pair<pair<int,int>,int> temp = s.front();
            s.pop();
            a = temp.first.first;
            b = temp.first.second;
            d = temp.second;
            if (a==x && b==y)
            {
                return d;
            }
            for (int i=0;i<8;i++)
            {
                int t1 = a + one[i];
                int t2 = b + sec[i];
                if (abs(t1)+abs(t2)<=300 && mat[t1 + 300][t2+300]==0)
                {
                    mat[t1+300][t2+300]=1;
                    s.push(make_pair(make_pair(t1,t2),d+1));
                }
            }
        }
        return -1;
    }
};
