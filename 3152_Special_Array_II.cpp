// 535/536
// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<bool>ans;
//         for(int i=0;i<queries.size();i++){
//             int k=queries[i][0];int j=queries[i][1];
//             bool flag=true;
//             int start=k+1;
//             for(int x=start;x<=j;x++){
//                 if((nums[x]%2==0 && nums[x-1]%2==1)||(nums[x-1]%2==0 && nums[x]%2==1)){
//                     flag=true;
//                     continue;
//                 }
//                 else{
//                     flag=false;
//                     break;
//                 }
//             }
//             ans.push_back(flag);
//         }
//         return ans;
        
//     }
// };

// Official Solution
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0); 
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }
        vector<bool> ans; 
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }
        return ans; 
    }
};
