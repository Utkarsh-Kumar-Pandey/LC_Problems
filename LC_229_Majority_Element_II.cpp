class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>ans;
        vector<int>answer;

        for(int i=0;i<nums.size();i++){
            ans[nums[i]]++;
        }

        for(auto it:ans){
            if(it.second>n/3){
                answer.push_back(it.first);
            }
        }
        return answer;
        
    }
};