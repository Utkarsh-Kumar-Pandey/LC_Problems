class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int first=g.size();
        int second=s.size();
        int l=0,r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(l<first && r<second){
            if(s[r]>=g[l]){
                count+=1;
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return count;
    }
};
