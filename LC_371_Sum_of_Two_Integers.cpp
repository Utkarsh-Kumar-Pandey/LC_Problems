class Solution {
public:
    int getSum(int a, int b) {
        // Carry by doing the &
        // Addition through ^
        while(b!=0){
            int carry=a&b;
            a=a^b;
            // Left shift
            b=carry<<1;
        }
        return a;
    }
};
