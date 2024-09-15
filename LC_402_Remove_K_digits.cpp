// In this question an approach is to remove k greater digits from the starting. 
// Edge case is k==num.size() return "0".
// Remove the initial zeros in starting.
// Remove the last values of stack when k is left.
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            // pop condition
            while(!st.empty() && k>0 && num[i]-'0'<st.top()-'0'){
                st.pop();
                k=k-1;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k=k-1;
        }
        if(st.empty()){
            return "0";
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        // Removing zeros coming in the start 
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty()){
            return "0";
        }
        return ans;
        
    }
};
/*
if(ans.empty()){
    return "0";
}
num ="10"
k =1
Output
""
Expected
"0"
*/