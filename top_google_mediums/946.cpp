class Solution {
public:
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i,j=0;
        for(i=0; i<pushed.size(); i++){
            st.push(pushed[i]);
            if (popped[j] == st.top()){
               
                while(!st.empty() && popped[j] == st.top()){
                    st.pop();
                    j++;
                };
                
            };    
        }
        
    
    if (st.size()==0)
        return true;
    else return false;
        
    }


};

/*


*/

