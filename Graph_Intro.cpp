/*
Basics of graph

Vertex/(Node)- Representing the value of entity 

Edge: Connection between two vertices An edge can either be directed (one-way) or undirected (two-way).

Directed Graph (Digraph): Edges have a direction

Undirected Graph: Edges do not have any specific direction

Weighted Graph: Edges have weights or costs associated 

Cyclic Graph: A graph that contains at least one cycle*/

class Solution {
  public:
    long long count(int n) {
        // your code here
        return (long long) pow(2,n*(n-1)/2);
    }
};