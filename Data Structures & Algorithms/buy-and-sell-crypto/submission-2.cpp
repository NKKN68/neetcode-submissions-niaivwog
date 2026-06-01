class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, maxlai = 0;
        for(int right = 1; right < prices.size(); right++){
            if(prices[right] > prices[left]){
                int lai = prices[right] - prices[left];
                maxlai = max(maxlai, lai);
            } else {
                left = right;
            }
        }
        return maxlai;
    }
};
