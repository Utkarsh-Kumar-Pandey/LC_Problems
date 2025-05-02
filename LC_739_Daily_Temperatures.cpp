// A pre requisite to this question is you must know how to find the NGE
// This is the implementation, for converting a higher complex method into an efficient approachh by using a monotonic stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int j = n - 1; j >= 0; j--) {
            // check the remperatures value at that specific index not thatindex
            while (!st.empty() && temperatures[st.top()] <= temperatures[j]) {
                st.pop();
            }
            if (!st.empty()) {
                res[j] = st.top() - j;
            }
            st.push(j);
        }
        return res;
    }
};

