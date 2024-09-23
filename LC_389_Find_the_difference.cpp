class Solution {
public:
    char findTheDifference(string s, string t) {
        char result=0;
        for(char c:s){
            result^=c;
        }
        for(char c:t){
            result^=c;
        }

        return result;
        
    }
};
/*
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ans;
        for(auto i: t){
            ans[i]++;
        }
        for(auto i : s){
            ans[i]--;
        }
        for(auto i : ans){
            if(i.second == 1){
                return i.first;
                
            }
        }
        return ' ';
    }
};*/