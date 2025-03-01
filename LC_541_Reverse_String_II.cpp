class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            reverse(s.begin() + i, s.begin() + min(i + k, n));
            i += 2 * k;
        }
        return s;
    }
};
