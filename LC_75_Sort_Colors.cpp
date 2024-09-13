//Dutch National Flag problem 
//Most Optimal solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;   
            }
        }
    }
};

//2nd Method
class Solution {
public:
    void sortColors(vector<int>& nums) {
           sort(nums.begin(),nums.end());
    }
};

//3rd Method 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0;
        int count1=0;
        int count2=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count0+=1;
            }
            else if(nums[i]==1){
                count1+=1;
            }
            count2+=1;
        }
        for(int i=0;i<count0;i++){
            nums[i]=0;
        }
        for(int j=count0;j<count1+count0;j++){
            nums[j]=1;
        }
        for(int k=count1+count0;k<nums.size();k++){
            nums[k]=2;
        }

        
    }
};
 


