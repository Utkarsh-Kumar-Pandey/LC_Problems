// Watched the Solution 
// https://www.youtube.com/watch?v=q_a6lpbKJdw
// We cannot initialize a queue as queue<TreeNode*, pair<int, int>> q;
// Because queue can only store a single type of element.
class Solution {
public:
    // store it as Node,(vertical,level)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mpp; //vertical level node
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            // pair<TreeNode*, pair<int, int>> p = q.front();
            auto p=q.front();
            q.pop();

            TreeNode*node=p.first;
            int vertical=p.second.first;
            int level=p.second.second;

            mpp[vertical].push_back({level,node->val});

            if(node->left){
                q.push({node->left,{vertical-1,level+1}});
            }
            if(node->right){
                q.push({node->right,{vertical+1,level+1}});
            }

        }

        // Storing ans from the map
        vector<vector<int>>ans;
        for(auto&p:mpp){
            sort(p.second.begin(),p.second.end());
            vector<int> vlevel;
            for (auto& node : p.second) {
                vlevel.push_back(node.second);
            }
            ans.push_back(vlevel);
        }
        return ans;
    }
};