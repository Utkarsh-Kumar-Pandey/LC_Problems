class Solution {
public:
    string toLowerCase(std::string s) {
        string res = "";
        for (auto c : s) {
            if ('A' <= c && c <= 'Z')
                res += c - 'A' + 'a';
            else
                res += c;
        }
        return res;
    }
};
