class Solution {
public:
    string finalString(string s) {
        string ans = "";
        string rev = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != 'i') {
                rev += s[i];
            }
            if (s[i] == 'i') {
                reverse(rev.begin(), rev.end());
            }
        }
        return rev;
    }
};

