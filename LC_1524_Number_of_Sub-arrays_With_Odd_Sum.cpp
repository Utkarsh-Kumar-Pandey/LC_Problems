class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // When the odd sum can be made??
        // when the sum is odd+even=odd_sum =>odd=odd_sum-even
        // other way is even - odd kare tab bhi
        int even = 1;
        int odd = 0;
        int ans = 0;
        int sum = 0;
        int n = arr.size();

        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                // if even then adding odd would give odd
                ans = (ans + odd) % MOD;
                even++;
            } else {
                // If odd then adding even would result in odd
                ans = (ans + even) % MOD;
                odd++;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    bool isodd(int x) {
        if (x % 2 == 0) {
            return false;
        }
        return true;
    }
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        vector<int> prefix(n, 0);
        // prefix[0]=1;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (isodd(sum)) {
                    if(i==0){
                        prefix[i] = 1 + 0;
                        ans+=1;

                    }
                    if (i > 0) {
                        prefix[i] = 1 + prefix[i - 1];
                        ans += 1;
                    }
                }
            }
        }
        return ans;
    }
};
*/
