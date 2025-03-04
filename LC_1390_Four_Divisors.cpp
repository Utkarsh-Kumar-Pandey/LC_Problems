// My approach
class Solution {
public:
int sum4div(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            s+=i;
        }
        continue;
    }
    return s;
}
bool is4div(int num){
    int count=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }
    if(count==4){
        return true;
    }
    return false;
}
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(is4div(nums[i])){
                sum+=sum4div(nums[i]);
            }
        }
        return sum;
        
    }
};

// Official solution 
class Solution {
public:
    int sum4div(int n) {
        int s = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                s += i;
                if (i != n / i) {
                    s += n / i;
                }
            }
        }
        return s;
    }
    bool is4div(int num) {
        int count = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                count++;
                if (i != num / i) {
                    count++;
                }
                if (count > 4)
                    return false;
            }
        }
        return count == 4;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (is4div(nums[i])) {
                sum += sum4div(nums[i]);
            }
        }
        return sum;
    }
};
