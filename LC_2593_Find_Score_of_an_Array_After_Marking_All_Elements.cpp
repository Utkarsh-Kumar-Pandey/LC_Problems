class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(int i=0;i<nums.size();i++){
            minh.push({nums[i],i});
        }
        long long ans=0;

        while(!minh.empty()){
            pair<int,int>topp=minh.top();
            minh.pop();
            int curr_value=topp.first;
            int curr_index=topp.second;

            if(nums[curr_index]!=-1){ //If not marked already
                ans+=curr_value;

                nums[curr_index]=-1;

                if(curr_index>0 && nums[curr_index-1]!=-1){
                    nums[curr_index-1]=-1;
                }
                if(curr_index<nums.size()-1 && nums[curr_index+1]!=-1){
                    nums[curr_index+1]=-1;
                }
            } 
        }
        return ans;
        
    }
};
