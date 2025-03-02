class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            // Jaise hi condition fulfill,
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};

/*
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
};
*/
