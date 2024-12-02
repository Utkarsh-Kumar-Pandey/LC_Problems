class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            if(mpp.find(2*arr[i])!=mpp.end()){
                return true;
            }
            else if(arr[i]%2==0 && mpp.find(arr[i]/2)!=mpp.end()){
                return true;
            }
            mpp[arr[i]]=i;
        }
        return false;
    }
};
/*class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]==arr[i]*2){
                    return true;
                }
                else if(arr[i]==arr[j]*2){
                    return true;
                }
            }
        }
        return false;
        
    }
};*/
