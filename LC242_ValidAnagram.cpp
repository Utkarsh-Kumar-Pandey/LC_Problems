//My approach
// store the frequency of character of first string then subtract while traversing other
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>ans;

        for(auto x:s){
            ans[x]++;
        }
        for(auto x:t){
            ans[x]--;
        }

        for(auto it:ans){
            if(it.second!=0){
                return false;
            }
        }
        return true;
        
    }
};

// Other Approach
// Sort the strings then check they are equal throughout or not
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s==t){
            return true;
        }
        return false;
    }
};