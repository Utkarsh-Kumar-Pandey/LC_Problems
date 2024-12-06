class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>mpp;
        for(int i=0;i<banned.size();i++){
            mpp[banned[i]]++;
        }
        vector<int>check;
        for(int i=1;i<=n;i++){
            int x=i;
            if(mpp.find(x)==mpp.end()){
                check.push_back(x);
            }
        }
        sort(check.begin(),check.end());

        for(int k=0;k<check.size();k++){
            cout<<check[k]<<endl;
        }

        int z=0;
        int maxi=INT_MIN;
        int sum=0;
        while(z<check.size()){
            sum+=check[z];
            if(sum<=maxSum){
                maxi=max(maxi,z+1);
            }
            z++;
        }
        if(maxi==INT_MIN){
            return 0;
        }
        else{
            return maxi;
        }
    }
};
