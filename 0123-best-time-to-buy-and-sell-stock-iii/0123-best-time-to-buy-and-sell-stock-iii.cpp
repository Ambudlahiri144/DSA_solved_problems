class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> front(5,0);
        vector<int> curr(5,0);
        
        for(int i = n-1;i>=0;i--){
            for(int trans = 0;trans <= 3;trans++){
                
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