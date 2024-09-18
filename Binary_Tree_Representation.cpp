//Binary Tree Representation from a given vector
class Solution{
public:

    void create_tree(node* root0, vector<int> &vec){
    if (vec.empty()) return;
    root0->data = vec[0]; 
    
    queue<node*> q;
    q.push(root0);

    int i = 1;
    while (i < vec.size()) {
        node* current = q.front();
        q.pop();

        if (i < vec.size()) {
            current->left = newNode(vec[i]);
            q.push(current->left);           
            i++;
        }

        if (i < vec.size()) {
            current->right = newNode(vec[i]);
            q.push(current->right);          
            i++;
        }
    }
    }

};