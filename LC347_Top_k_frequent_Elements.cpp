class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Solve using max heap 
        unordered_map<int,int>mpp;
        priority_queue<pair<int,int>>pq;
        vector<int>result;

        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            pq.push({it.second,it.first}); 
            // The priority queue stores the element in the form of pair
        }
        // This will store the Frequeny->Number

        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            // 
            pq.pop();
        }
        return result;
        
    }
};

// My  wrong first approach 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mpp;

        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto it:mpp){
            ans.push_back(it.second);
        }
        sort(ans.begin(),ans.end());
        vector<int>result;
        for(int j=0;j<k;j++){
            result.push_back(ans[j]);
        }

        return result;
        
    }
};