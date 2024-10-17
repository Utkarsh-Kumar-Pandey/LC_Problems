class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,int>ans;
        for(int i=0;i<heights.size();i++){
            ans[heights[i]]=i;
        }
        sort(heights.begin(),heights.end());
        vector<string>answer;
        for(int i=0;i<heights.size();i++){
            answer.push_back(names[ans[heights[i]]]);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};