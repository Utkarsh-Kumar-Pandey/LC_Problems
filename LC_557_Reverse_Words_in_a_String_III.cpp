class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string rev = "";
        int i = 0;
        while (i <= s.size() - 1) {

            while (i <= s.size() - 1 && s[i] != ' ') {
                rev += s[i++];
            }
            reverse(rev.begin(), rev.end());
            ans += rev;
            rev = "";
            if (i < s.size() - 1) {
                ans += ' ';
            }
            i++;
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};


