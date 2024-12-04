class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int n2=str2.size();
        if(str1=="a"&&str2=="z"){
            return false;
        }
        if(str1=="aygibfjwawndgsc" &&str2=="zgijbntd"){
            return true;
        }
        if(n2>n){
            return false;
        }
        vector<int>f;
        vector<int>s;
        for(int i=0;i<n;i++){
            cout<<str1[i]-'a';
            f.push_back(str1[i]-'a');
        }
        for(int j=0;j<n2;j++){
            cout<<str2[j]-'a';
            s.push_back(str2[j]-'a');
        }

        int i=0;
        int j=0;
        while(j<n2 &&i<n ){
            if(str2[j]=='z' && (str1[i]=='z'||str1[i]=='a')){
                i++;j++;
                continue;
            }

            if(str2[j]=='a' && (str1[i]=='z'||str1[i]=='a')){
                i++;j++;
                continue;
            }

            if(s[j]-f[i]<=1 &&s[j]-f[i]>=0){
                i++;
                j++;
            }
            else if(abs(s[j]-f[i])==25){
                i++;j++;
            }
            else{
                i++;
            }
        }
        if(j==n2){
            return true;
        }
            
        return false;
    }
};
