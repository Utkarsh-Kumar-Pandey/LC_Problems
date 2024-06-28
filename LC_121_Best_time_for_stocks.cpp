
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int mini = prices[0];

        for (int i = 0; i < n; i++) {

            if (prices[i] < mini) {
                mini = prices[i];
            }
            int sum = prices[i] - min;
            maxprofit = max(maxprofit, sum);
        }

        return maxprofit;
    }
};