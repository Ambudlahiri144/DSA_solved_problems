class Solution {
public:
    int findWays(vector<int>& arr, int k)
    {
        // Write your code here.
        int mod = (7+1e9);
        int n = arr.size();
        vector<int> prev(k+1,0),curr(k+1);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;
        for(int i = 1;i < n;i++){
            for(int j = 0;j<=k;j++){
                int not_take = prev[j];
                int take = 0;
                if(arr[i] <= j) take = prev[j-arr[i]];
                curr[j]  = (take + not_take);
            }
            prev = curr;
        }
        return prev[k];

    }
    int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
        int tot_Sum = 0;
        for(auto &it:arr) tot_Sum += it;
        if(tot_Sum - d < 0 || (tot_Sum - d) % 2 ) return false;
        return findWays(arr,(tot_Sum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }
};