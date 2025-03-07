class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> st;
        vector<int> ans(2, -1);
        vector<int> check(right + 1, 1);
        check[0] = check[1] = 0;
        for (int i = 2; i * i <= right; i++) {
            if (check[i]) {
                for (int j = i * i; j <= right; j += i) {
                    check[j] = 0;
                }
            }
        }
        for (int k = max(left, 2); k <= right; k++) {
            if (check[k] == 1) {
                st.push_back(k);
            }
        }
        if (st.size() <= 1) {
            return {-1, -1};
        }
        int mini = INT_MAX;
        for (int i = 0; i < st.size() - 1; i++) {
            int diff = st[i + 1] - st[i];
            if (diff < mini) {
                mini = diff;
                ans[0] = st[i];
                ans[1] = st[i + 1];
            }
        }

        return ans;
    }
};
