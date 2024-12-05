class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int j=1;j<=nums.size()+1;j++){
            int findi=int(j);
            if(st.find(findi)==st.end()){
                return int(j);
            }
        }
        return -1; 
    }
};
