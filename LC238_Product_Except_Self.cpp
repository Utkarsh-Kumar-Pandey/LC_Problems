//NC Explanation
// [1,2,3,4]
// prefix=[1,1,2,6]
// postfix=[24,12,4,1]
// result=[24,12,8,6] multiply


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,1);
        vector<int>prefix(n,1);
        vector<int>postfix(n,1);
    
        for(int i=1;i<n;i++){
            prefix[i]*=prefix[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--){
            postfix[i]*=postfix[i+1]*nums[i+1];
        }

        for(int i=0;i<n;i++){
            result[i]=prefix[i]*postfix[i];
        }
        return result;
        
    }
};