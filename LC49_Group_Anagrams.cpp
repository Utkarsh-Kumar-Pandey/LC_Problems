class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string,vector<string>>ans;

        for(auto st:strs){
            string newst=st;
            sort(newst.begin(),newst.end());
            ans[newst].push_back(st);

            // Sorted string mapped with the original strings 
        }

        for(auto it:ans){
            res.push_back(it.second);
            // it.second has the vector of anagram strings
        }
        return res;   
    }
};
