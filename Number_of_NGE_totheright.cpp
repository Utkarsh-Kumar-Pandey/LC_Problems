//My approach gave a TLE
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        unordered_map<int,int>mpp;
        vector<int>ans(queries,0);
        
        for(int i=0;i<arr.size();i++){
            int count=0;
            
            for(int j=n-1;j>i;j--){
                if(arr[j]>arr[i]){
                    count++;
                }
                
            }
            mpp[i]=count;
        }
        for(int k=0;k<queries;k++){
            int idx = indices[k];
            if (idx >= 0 && idx < n) {
                ans[k] = mpp[idx];
            } 
            else {
                ans[k] = 0;
            }
        }
        return ans;  
    }
};

//Watched this solution 
class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int>ans;
        for(int i=0;i<queries;i++){
            int bound=indices[i];
            // this provides the index
            int count=0;
            for(int j=n-1;j>bound;j--){
                if(arr[j]>arr[indices[i]]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
       
    }

};
