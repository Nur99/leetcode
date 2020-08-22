class Solution {
public:
    string decodeString(string s) {
    	for(int i = 0; i < s.size(); i++){
    		if(s[i] == ']'){
    			string temp = "";
    			while(1){
    				char top = st.top();
    				st.pop();
    				if(top == '['){
    					break;
    				}
    				temp += top;
    			}
    			reverse(temp.begin(), temp.end());
    			string l = "";
    			while(st.size() && st.top() >= '0' && st.top() <= '9'){
    				l += st.top();
    				st.pop();
    			}
    			reverse(l.begin(), l.end());
    			int k = intify(l);
    			string temp2 = "";
    			while(k--){
    				temp2 += temp;
    			}
    			for(char c: temp2){
    				st.push(c);
    			}
    		}
    		else{
    			st.push(s[i]);
    		}
    	}

    	while(st.size()){
    		ans += st.top();
    		st.pop();
    	}

    	reverse(ans.begin(), ans.end());

    	return ans;
    }

    int intify(string l){
    	//234
    	//432
    	int e = pow(10, l.size() - 1), deg = 0;

    	for(char c: l){
    		deg += e * (c - '0');
    		e /= 10;
    	}
    	return deg;
    }

private:
	stack <char> st;
	string ans = "";
};
