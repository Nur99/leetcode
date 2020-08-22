class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if(!matrix.size())return 0;
    	vector <vector<int>> dp(matrix.size(), vector <int>(matrix[0].size(), 0));

    	for(int i = 0; i < matrix.size(); i++){
    		if(i == 0){
    			for(int j = 0; j < matrix[i].size(); j++){
    				if(matrix[i][j] == '1')dp[i][j] = 1;
    			}
    			continue;
    		}
    		for(int j = 0; j < matrix[i].size(); j++){
    			if(matrix[i][j] == '1'){
    				dp[i][j] += dp[i - 1][j] + 1;
    			}
    		}
    	}
    	int answer = 0;
    	for(int i = 0; i < matrix.size(); i++){
    		answer = max(answer, get_for_each_row_2(dp[i]));
    		cout<<answer<<endl;
    	}
    	return answer;
    }
    
private:
	int get_for_each_row_2(vector <int>& hist){
		int n = hist.size();
		int i = 0;
		stack <int> s;
		int max_for_row = 0;
		int answer = 0;

		while(i < n){
			if(s.empty() || hist[s.top()] <= hist[i]){
				s.push(i++);
			}
			else{
				int pre_top_index = s.top();
				s.pop();
				int cur_top_index = -1;
				if(s.size()){
					cur_top_index = s.top();
				}
                int a = (i - cur_top_index - 1), b = hist[pre_top_index];
                int c = min(a, b);
                int temp_max = c * c;
				answer = max(answer, temp_max);
			}
		}

		while(s.size()){
			int pre_top_index = s.top();
			s.pop();
			int cur_top_index = -1;
			if(s.size()){
				cur_top_index = s.top();
			}
            int a = (i - cur_top_index - 1), b = hist[pre_top_index];
            int c = min(a, b);
            int temp_max = c * c;
			answer = max(answer, temp_max);
		}

		return answer;
	}
};
