// My approach
class Solution {
public:
    bool isvowel(char x) {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
            x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (isvowel(s[i]) && isvowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } 
            else if (isvowel(s[i]) && !isvowel(s[j])) {
                j--;
            } 
            else {
                i++;
            }
        }
        return s;
    }
};








class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                 s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                 s[i] == 'O' || s[i] == 'U') &&
                (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                 s[j] == 'u' || s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                 s[j] == 'O' || s[j] == 'U')) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                        s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                        s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                        s[i] == 'U') &&
                       (s[j] != 'a' && s[j] != 'e' && s[j] != 'i' &&
                        s[j] != 'o' && s[j] != 'u' && s[j] != 'A' &&
                        s[j] != 'E' && s[j] != 'I' && s[j] != 'O' &&
                        s[j] != 'U')) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};
