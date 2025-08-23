class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int mini=prices[0];
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++){
            int profit=prices[i]-mini;
            maxProfit=max(maxProfit,profit);
            mini=min(mini,prices[i]);
        }
    return maxProfit;
    }
};