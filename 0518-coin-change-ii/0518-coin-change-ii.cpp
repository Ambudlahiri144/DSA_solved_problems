class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int k = 0;k <= amount;k++){
            prev[k] = (k % coins[0] == 0);
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<=amount;j++){
                long not_take = prev[j];
                long take = 0;
                if(coins[i] <= j) take = curr[j - coins[i]];
                curr[j] = take + not_take;
            }
            prev = curr;
        }
        long ans = prev[amount];
        return ans;
        
    }
};