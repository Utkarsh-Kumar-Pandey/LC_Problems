struct Item{
    int value;
    int weight;
};

class Solution {
  public:
//   Making out the comparator for sorting 
bool static comparator(Item a, Item b){
    double x=(double)a.value/a.weight;
    double y=(double)b.value/b.weight;
    return x>y;
}
    double fractionalKnapsack(vector<int>& value, vector<int>& weight, int capacity) {
        double ans=0;
        vector<Item>vec1;
        for(int i=0;i<value.size();i++){
            vec1.push_back({value[i],weight[i]});
        }
        sort(vec1.begin(),vec1.end(),comparator);
        
        // now we will go through the vector searching for the weights 
        for(int i=0;i<vec1.size();i++){
            if(vec1[i].weight<=capacity){
                ans+=vec1[i].value;
                capacity-=vec1[i].weight;
            }
            else{
                ans += ((double)vec1[i].value / vec1[i].weight) * capacity;
                // If already filled stop the traversal for next ones
                break;
                
            }
        }
        return ans;
        
    }
};
