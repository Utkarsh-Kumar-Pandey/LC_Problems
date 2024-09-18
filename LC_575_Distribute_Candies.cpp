class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int>ans;
        int n=candyType.size();
        for(int i=0;i<n;i++){
            ans.insert(candyType[i]);
        }
        int s=ans.size();
        int half=n/2;
        if(half>=s){
            return s;
        }
        return half;
        
    }
};