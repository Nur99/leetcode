class Solution {
public:
    void reverseStr(string& str) { 
        int n = str.length(); 
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        
        string answer = "";
        int toAddOne = 0;
        while (true) {
            int tempSum = 0;
            if (i < 0 && j >= 0) {
                tempSum = 0 + b[j] - '0';  
            } else if (j < 0 && i >= 0) {
                tempSum = a[i] - '0' + 0;  
            } else if (j < 0 && i < 0) {
                break;
            } else {
                // cout<<"a[i]="<<a[i]<<"; b[j]="<<b[j]<<endl;
                tempSum = a[i] - '0' + b[j] - '0';   
            }
            answer += (tempSum + toAddOne)%2 + '0';
            // cout<<"answer="<<answer<<endl;
            toAddOne = (tempSum + toAddOne)/2;
            // cout<<"toAddOne="<<toAddOne<<endl;
            i--;
            j--;
        }
        if (toAddOne > 0) answer += '1';
        reverseStr(answer);
        return answer; 
    }
};
