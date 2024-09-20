
class Solution {
  public:
    int temp=0;
    int height(Node*root){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        
        temp=max(temp,left+right);
        
        return 1+max(left,right);
        
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        int ans=height(root);
        return temp+1;
    }
};