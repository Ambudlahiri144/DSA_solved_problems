class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> front(2,0) , curr(2,0);
        front[0] = front[1] = 0;
        for(int i = n-1;i>=0;i--){
            
                
            curr[1] = max(-prices[i] + front[0],front[1]);
                
                
            curr[0] = max(prices[i] - fee + front[1],front[0]);
                
                

            
            front = curr;
        }
        return front[1];
        
    }
};