class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                // Checking if the stack is not empty and the current asteroid is in opposite direction with lesser value
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();  
                }
                // If stack has the top value same as the current asteroid value in opposite direction
                if (!st.empty() && st.top() == abs(asteroids[i])) {
                    st.pop();  
                } 
                // This condition is written for handling if atlast only negative valued of the asteroid is stored 
                else if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);  
                }
            }
            
        }
        // Making the stack empty and reversing for the answer
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

/* Why this condition is checked in while loop st.top()>0
asteroids =
[-2,-1,1,2]
Use Testcase
Output
[-1,1,2]
Expected
[-2,-1,1,2]
*/