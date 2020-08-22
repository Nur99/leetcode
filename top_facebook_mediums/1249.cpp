class Solution {
public:
    string minRemoveToMakeValid(string s) {
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' && st.size() && st.top().first == '('){
                st.pop();    
            }
            else if(s[i] == '(' || s[i] == ')'){
                st.push(make_pair(s[i], i));
            }
        }

        string ans = "";

        for(int i = s.size() - 1; i >= 0; i--){
            if(st.size() && i == st.top().second){
                st.pop();
            }
            else{
                ans += s[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    stack <pair <char, int> > st;
};

