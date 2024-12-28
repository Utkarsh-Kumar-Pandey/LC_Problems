class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int row=points.size();
        double maxi=INT_MIN;
        for(int i=0;i<row-2;i++){
            for(int j=i+1;j<row-1;j++){
                for(int k=j+1;k<row;k++){
                    int xf=points[i][0];
                    int xs=points[j][0];
                    int xt=points[k][0];
                    int yf=points[i][1];
                    int ys=points[j][1];
                    int yt=points[k][1];
                    // Now the formula
                    double ans=0.5*(abs(xf*(ys-yt)+xs*(yt-yf)+xt*(yf-ys)));
                    maxi=max(maxi,ans);
                }
            }
        }
        return maxi;

        
    }
};
