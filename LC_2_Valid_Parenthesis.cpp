class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            }  
            else {
                // Checking the condition that initially if closing brackets are there and stack is empty 
                // example- "]" In else block it checcks if the stack is empty before the rest condition 
                if (st.empty()) {
                    return false;
                }

                if (i == ')' && st.top() == '(') {
                    st.pop();
                } 
                else if (i == '}' && st.top() == '{') {
                    st.pop();
                } 
                else if (i == ']' && st.top() == '[') {
                    st.pop();
                } 
                else {
                    return false;
                }
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }
};