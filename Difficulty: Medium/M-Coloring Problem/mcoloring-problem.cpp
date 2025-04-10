//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSafe(int node,int color[],bool graph[101][101],int v,int col){
        for(int k = 0;k < v;k++){
            if(k != node && graph[k][node] == 1 && color[k] == col) return false;
        }
        return true;
    }
    bool solve(int node,int color[],int m,int v,bool graph[101][101]){
        if(node == v){
            return true;
        }
        for(int i = 1;i<=m;i++){
            if(isSafe(node,color,graph,v,i)){
                color[node] = i;
                if(solve(node+1,color,m,v,graph)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        bool graph[101][101] = {false};
    
    
        for(auto edge : edges) {
            int u = edge.first;
            int w = edge.second;
            graph[u][w] = true;
            graph[w][u] = true;  
        }
        
        int color[v] = {0};
        if(solve(0, color, m, v, graph)) return true;
        return false;
            
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends