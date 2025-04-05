//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct meeting{
    int start,end,pos;
};
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comp(struct meeting m1,meeting m2){
        if(m1.end == m2.end)
            return m1.pos < m2.pos;
        return m1.end < m2.end;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        struct meeting m[n];
        for(int i = 0;i < n;i++){
            m[i].start = start[i];
            m[i].end = end[i];
            m[i].pos = i+1;
            
        }
        sort(m,m+n,comp);
        int count = 1;
        int freetime = m[0].end;
        for(int i = 1;i<n;i++){
            if(m[i].start > freetime){
                count++;
                freetime = m[i].end;
            }
        }
        return count;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends