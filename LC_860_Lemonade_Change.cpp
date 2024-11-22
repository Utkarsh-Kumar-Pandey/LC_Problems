class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Storing out the counts for 5 and 10 coins 
        int count5 = 0;
        int count10 = 0;

        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                count5++;
            }
            if (bills[i] == 10) {
                count10++;
                // Conditions for 10rs coin 5 must be present to give back.
                if (count5 > 0) {
                    count5--;
                } else {
                    return false;
                }
            }
            if (bills[i] == 20) {
                // If there's $20 coin there would be 2 possibility
                // 1 $10 coin and 1 $5 coin
                // 3 $5 coin required
                if (count10 > 0 and count5 > 0) {
                    count10--;
                    count5--;
                } else if (count5 >= 3) {
                    count5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
