// Considering a good test case,
// Input: str1 = "ABABAB", str2 = "ABAB"
// Output: "AB"

// Official solution to this q
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // approaching with checking the concatenation,
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // Finding out the gcd length
        int len = gcd(str1.size(), str2.size());
        // The gcd lengthd string is repeating out throughout.
        return str1.substr(0, len);
    }
};


