// My solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int longestcount = 1;
        if (n == 0) {
            return 0;
        }
        for (int i = 1; i < n; i++) {
            // check if the previous element has occured just before
            if (nums[i - 1] == nums[i]) {
                continue;
            }
            // if it is greater than by 1 value then,
            else if (nums[i] == nums[i - 1] + 1) {
                count++;
                longestcount = max(longestcount, count);
            }

            else {
                count = 1;
            }
        }
        return longestcount;
    }
};

// Using Hash<set>
// finding the next consecutive element in set and incrementing the count value
// accordingly
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest_cons = 1;
        unordered_set<int> sett;
        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            sett.insert(nums[i]);
        }
        // Traversing in the set
        for (auto it : sett) {
            if (sett.find(it - 1) == sett.end()) {
                // If 1 less value not found [this is the first one]
                int first = it;

                int count = 1;
                // if the next value is found in the set then increment the
                // count
                while (sett.find(it + 1) != sett.end()) {
                    count += 1;
                    it += 1;
                }
                longest_cons = max(longest_cons, count);
            }
        }
        return longest_cons;
    }
};