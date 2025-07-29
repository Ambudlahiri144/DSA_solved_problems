class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> front(2*k+1,0);
        vector<int> curr(2*k+1,0);
        // front[0] = curr[0] = 0;
        for(int i = n-1;i>=0;i--){
            for(int trans = 2*k-1;trans >= 0;trans--){
                
                int profit = 0;
                if(trans % 2 == 0){
                    profit = max(-prices[i] + front[trans+1],front[trans]);
                }
                else{
                    profit = max(prices[i] + front[trans+1],front[trans]);
                }
                curr[trans] = profit;

            
            }
            front = curr;
        }
        return front[0];
        
    }
};