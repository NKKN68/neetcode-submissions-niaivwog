class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int laimax = INT_MIN;
        int lai;
        for(int right = 1; right < prices.size(); right++){
            left = 0;
            lai = prices[right] - prices[left];
            while(right > left){
                laimax = max(laimax, lai);
                lai = prices[right] - prices[left + 1];
                left++;
            }
        }
        if(laimax <= 0) return 0;
        return laimax;
    }
};
