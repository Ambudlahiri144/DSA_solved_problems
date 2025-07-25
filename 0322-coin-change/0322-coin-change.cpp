class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int k = 0;k <= amount;k++){
            if(k % coins[0] == 0) prev[k] = k/coins[0];
            else prev[k] = 1e9;
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                int not_take = prev[j];
                int take = INT_MAX;
                if(coins[i] <= j) take = 1 + curr[j - coins[i]];
                curr[j] = min(take,not_take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;


    }
};