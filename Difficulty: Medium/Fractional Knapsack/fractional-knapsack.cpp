//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool cmp(const pair<double,pair<int,int>> &a, const pair<double,pair<int,int>> &b){
    return a.first > b.first;
}
class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        int n = val.size(), weight = 0;
        double value = 0.0;
        vector<pair<double,pair<int,int>>> v;
        for(int i=0; i<n; i++){
            v.push_back({(double)val[i]/wt[i], {val[i], wt[i]}});
        }
        sort(v.begin(), v.end(), cmp);
        for(int i=0; i<n; i++){
            if(weight < capacity){
                int currV = v[i].second.first, currW = v[i].second.second;
                double ratio = v[i].first;
                if(weight+currW > capacity){
                    double extra = (capacity-weight)*ratio;
                    value += extra;
                    break;
                }
                else{
                    weight += currW;
                    value += (double)currV;
                }
            }
        }
        return value;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends