class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        while (!st.empty()) {
            char x = st.top();
            st.pop();
            ans += x;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


