// class Solution {
// public:
//     int sumOfGoodNumbers(vector<int>& nums, int k) {
//         int sum=0;
//         int j=0;
//         while(j<k &&j+k<nums.size()){
//             if(nums[j]>nums[j+k]){
//                 sum+=nums[j];
//             }
//             j++;
//         }
//         int l=nums.size()-k;
//         while(l<nums.size() && l-k>=0){
//             if(nums[l]>nums[l-k]){
//                 sum+=nums[l];
//             }
//             l++;
//         }

//         for(int i=k;i<nums.size()-k;i++){
//             if(nums[i]>nums[i-k] &&nums[i]>nums[i+k]){
//                 sum+=nums[i];
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if((i-k)<0 && nums[i]>nums[i+k]){
                     sum=sum+nums[i];
                    cout<<int(i-k)<<endl;
                cout<<"check";
                cout<<sum<<endl;
                }
            else if((i+k)>=n && nums[i]>nums[i-k]){
                 sum=sum+nums[i];
                cout<<"checking";
                cout<<sum<<endl;
            }
            else if(i-k>=0 && i+k<=n-1 &&nums[i]>nums[i-k] &&nums[i]>nums[i+k]){
                sum+=nums[i];
            }
            
               
        }
        return sum;
    }
};
