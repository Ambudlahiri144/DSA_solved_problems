class Solution {
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftDiag,vector<int> &leftRow,vector<int> &upperDiag,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(leftRow[row] == 0 && leftDiag[row+col] == 0 && upperDiag[(n-1)+(col-row)] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftDiag[row+col] = 1;
                upperDiag[(n-1) + (col - row)] = 1;
                solve(col+1,board,ans,leftDiag,leftRow,upperDiag,n);
                board[row][col] = '.';
                leftRow[row] = 0;
                leftDiag[row+col] = 0;
                upperDiag[(n-1) + (col - row)] = 0;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i < n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0);
        vector<int> leftDiag(2*n-1,0);
        vector<int> upperDiag(2*n-1,0);
        solve(0,board,ans,leftDiag,leftRow,upperDiag,n);
        return ans;
        
    }
};