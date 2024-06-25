//My approach 1
//traversing through the string and storing it in other
//check if it is equal after reversing the resulted string
class Solution {
public:
    bool isPalindrome(string s) {
        string check = "";
        for (auto it : s) {
            if (isalnum(it)) {
                check += tolower(it);
            }
        }
        string check2 = check;
        reverse(check2.begin(), check2.end());
        if (check == check2) {
            return true;
        }
        return false;
    }
};

//My approach 2
//Using 2 pointers, checking the alphabets equal or not 
class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0;
        int high = s.size() - 1;

        while (low < high) {
            if (!isalnum(s[low])) {
                low++;
            } 
            else if (!isalnum(s[high])) {
                high--;
            } 
            else if (tolower(s[low]) != tolower(s[high])) {
                return false;
            } 
            else {
                low++;
                high--;
            }
        }
        return true;
    }
};
