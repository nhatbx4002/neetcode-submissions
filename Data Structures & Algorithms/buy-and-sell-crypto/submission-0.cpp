class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int max_value = 0 ; 
        int buy = 0 ; 
        int sell = 1 ; 

        while(sell < n){
            
            if(prices[buy] < prices[sell]){
                int profit = prices[sell] - prices[buy];

                max_value = max(profit,max_value);
            }else{

                buy = sell;
            }

            sell++;
        }

        return max_value;
    }
};
