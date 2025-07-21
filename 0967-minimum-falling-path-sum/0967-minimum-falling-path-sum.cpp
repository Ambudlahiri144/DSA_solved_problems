class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0),curr(m,0);
        for(int j = 0;j < m;j++){
            prev[j] = matrix[0][j];
        } 
        for(int i = 1; i< n;i++){
            for(int j = 0; j < m;j++){
                int up = matrix[i][j] + prev[j];
                int ldiag = matrix[i][j];
                if(j - 1 >= 0) ldiag += prev[j-1];
                else ldiag += 1e9;
                int rdiag = matrix[i][j];
                if(j + 1 < m) rdiag += prev[j+1];
                else rdiag += 1e9;
                curr[j] = min(up, min(ldiag,rdiag));
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(int j = 0;j < m;j++){
            mini = min(mini,prev[j]);
        }
        return mini;

        
    }
};