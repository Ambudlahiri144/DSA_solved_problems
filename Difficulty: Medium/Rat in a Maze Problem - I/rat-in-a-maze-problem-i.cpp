//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    void solve(int i,int j,vector<vector<int>> &mat,int n,vector<string> &ans,string move,vector<vector<int>> &vis,int di[],int dj[]){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for(int ind = 0;ind < 4;ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1){
                vis[i][j] = 1;
                solve(nexti,nextj,mat,n,ans,move + dir[ind],vis,di,dj);
                vis[i][j] = 0;
            }
        }
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,+1,0};
        if(mat[0][0] == 1) solve(0,0,mat,n,ans,"",vis,di,dj);
        return ans;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Endshttps://media.geeksforgeeks.org/img-practice/chatIcon-16535https://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg61581.svghttps://media.geeksforgeeks.org/img-practice/chatIcon-1653561581.svg