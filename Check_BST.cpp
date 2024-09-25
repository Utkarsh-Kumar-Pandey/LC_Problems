class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        vector<int>check=arr;
        sort(check.begin(),check.end());
        set<int>check2;
        for(auto it:check){
            check2.insert(it);
        }
        if(check2.size()!=check.size()){
            return false;
        }
        return check==arr;
    }
};
