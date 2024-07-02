// The error I made was checking check[s[i]-'a'], but these are lowercase
// characters and 66 / 108 testcases passed
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> check(26, 0);
        int n = s1.size();
        int n2 = s2.size();
        if (n > n2) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            check[s1[i] - 'a']++;
        }

        for (int i = 0; i < n2 - 1; i++) {
            vector<int> check2(26, 0);
            int j = i + 1;
            check2[s2[i] - 'a']++;
            check2[s2[j] - 'a']++;

            if (check == check2) {
                return true;
            }
        }
        return false;
    }
};

// Official Solution 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> check(26, 0);

        int n = s1.size();
        int n2 = s2.size(); 
        if (n > n2) {
            return false;
        }
        for (char c : s1) {
            check[c - 'a']++;
        }
        vector<int> check2(26, 0);
        for (int i = 0; i < n; i++) {
            check2[s2[i] - 'a']++;
        }
        if (check == check2) {
            return true;
        }
        for (int i = 1; i <= n2 - n; i++) {
            check2[s2[i - 1] - 'a']--;     
            check2[s2[i + n - 1] - 'a']++; 
            // Sliding the Window 
            if (check == check2) {
                return true;
            }
        }
        return false;
    }
};
