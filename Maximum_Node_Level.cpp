int maxNodeLevel(Node *root)
{
 // Add your code here
 if(root==NULL){
     return -1;
 }
 queue<Node*>q;
 q.push(root);
 
 int prev_size=0;
 int max_level=0; //nodes with maximum nodes
 int level=0; //current level
 
 while(!q.empty()){
     int current_size=q.size();
     
     if(current_size>prev_size){
         prev_size=current_size;
         max_level=level;
     }
     
     for(int i=0;i<current_size;i++){
         Node*curr=q.front();
         q.pop();
         
         if(curr->left){
             q.push(curr->left);
         }
         if(curr->right){
             q.push(curr->right);
         }
     }
     level++;
 }
 return max_level;
}
