class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string>ans;
        int mul_line=0,n=source.size();
        int i,j;
        string str="";
        for(i=0;i<n;i++){

            string temp=source[i];
            int len=temp.size();
            for(j=0;j<len;j++){
                if(mul_line==1){
                    if(j+1<len && temp[j]=='*' && temp[j+1]=='/'){
                        mul_line=0;
                        j++;
                    }
                }
                else{
                    if(mul_line==0 && j<len-1 && temp[j]=='/' && temp[j+1]=='/'){
                        if(str.size()>0)
                            ans.push_back(str);
                        str="";
                        break;
                    }
                    else if(mul_line==0 && j<len-1 && temp[j]=='/' && temp[j+1]=='*'){
                         mul_line=1;
                         j++;
                    }
                    else if(mul_line==0){
                        str=str+temp[j];
                    }  
                }

            }
            if(str.size()!=0 && mul_line==0){
                ans.push_back(str);
                str="";
            }      
        }

        return ans;
    }
};

