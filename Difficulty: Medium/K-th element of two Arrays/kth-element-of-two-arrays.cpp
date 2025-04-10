//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int m = a.size();
        int n = b.size();
        int low = max(0,k-n) , high = min(k,m);
        while(low <= high){
            int cut1 = (low + high) >> 1;
            int cut2 = k - cut1;
            int l1 = cut1 == 0?INT_MIN:a[cut1-1];
            int l2 = cut2 == 0?INT_MIN:b[cut2-1];
            int r1 = cut1 == m?INT_MAX:a[cut1];
            int r2 = cut2 == n?INT_MAX:b[cut2];
            if(l1 <= r2 && l2 <= r1) return max(l1,l2);
            else if(l1 > r2) high = cut1 - 1;
            else low = cut1 + 1;
            
        }
        return 1;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends