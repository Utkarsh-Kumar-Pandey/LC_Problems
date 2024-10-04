//https://www.youtube.com/watch?v=3oI-34aPMWM
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto it:edges){
            int u=it.first;
            int v=it.second;
            
            adj[u].push_back(v);   
            adj[v].push_back(u);   
        }
        return adj;
    }
};