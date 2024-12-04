//Learnt one thing if we use the variable as a global then we can use the variable afterwards when it gets used for un iterated part 
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int j = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (j < spaces.size()) {
                if (i == spaces[j]) {
                    ans += ' ';
                    j++;
                }
            }
            ans += s[i];
        }
        return ans;
    }
};
/*---------------------------------------------------------------------
class Solution
{
public:
    string addSpaces(string s, vector<int>& spaces)
{
        string ans="";
        int j=0;
        int i;
        for(i=0;i<s.size() && j<spaces.size();i++)
        {
            if(i==spaces[j])
            {
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        for(;i<s.size();i++)
        {
            ans+=s[i];
        }
        return ans;
    }
};
*/
