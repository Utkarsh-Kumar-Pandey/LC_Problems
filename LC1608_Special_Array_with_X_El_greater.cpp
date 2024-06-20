//MY SOLUTION
class Solution {
public:
    int specialArray(vector<int>& nums) {
        //Iterate through the vector
        for(int i=0;i<=nums.size();i++){
            //count value gets reinitialised
            int count=0;

            for(int j=0;j<nums.size();j++){
                if(nums[j]>=i){
                    count+=1;
                }
            }
            // check if the total count is equal to the number 
            if(count==i){
                return i;
            }
        }
        return -1;
        
    }
};