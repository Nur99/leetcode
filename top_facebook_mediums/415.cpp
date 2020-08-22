class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()){
            add_zeros(num1, num2.size() - num1.size());
        }   
        if(num1.size() > num2.size()){
            add_zeros(num2, num1.size() - num2.size());
        }     
        
        string ans = "";
        add_numbers(ans, num1, num2);

        return ans;
    }

private:
    void add_zeros(string& s, int k){
        reverse(s.begin(), s.end());
        while(k--){
            s += '0';
        }
        reverse(s.begin(), s.end());
    }

    void add_numbers(string& ans, string& a, string& b){
        int carry = 0;

        for(int i = a.size() - 1; i >= 0; i--){
            int sum = add_chars(a[i], b[i]) + carry;
            ans += char(sum % 10 + '0');
            carry = sum / 10;
        }

        if(carry){
            ans += char(carry + '0');
        }

        reverse(ans.begin(), ans.end());
    }

    int add_chars(char a, char b){
        return a + b - 2 * '0';
    }
};

