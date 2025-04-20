// Official solution 
// Approach by getting all the elements of the string 't' in a map 
// Checks the size as a first check whether the string 't' length doesn't exceeds 's' length
// Iterate the string s througout and check whether all are present or not (present{have}) == (need{required})
// If the condition gets fulfilled then we try to shring out the window from left and accordingly handle (present{have}) value
// The substring starting from the minimum length starting as stored already is used to return the substring from that index, here -> {min_starting}
// The size of substring is same as the minimum window length that fulfills the above conditions, mainly the 3rd one 
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        unordered_map<int, int> mpp;
        for (auto it : t) {
            mpp[it]++;
        }

        unordered_map<int, int> window_mpp;
        int left = 0;
        int mini = INT_MAX;
        // Number of elements that are present in the t string
        int need = mpp.size();
        // Number of elements that are present of the t part
        int curr_mpp_has = 0;
        // Store the index where the minimum substring starts
        int min_starting = 0;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            window_mpp[ch]++;

            // This condition is for checking that have is completed and the
            // window contains the element of t string If the element is present
            // in the map AND, If the required number of element is present same
            // as the t string
            if (mpp.find(ch) != mpp.end() && mpp[ch] == window_mpp[ch]) {
                curr_mpp_has++;
            }

            // if(curr_mpp_has==need){
            // mini = min(mini, i - left + 1);
            // }
            while (curr_mpp_has == need) {
                // Until the window has the characters which are needde,
                // We will shrink the window from left
                if (i - left + 1 < mini) {
                    mini = i - left + 1;
                    min_starting = left;
                }

                // If we will shrink the window and the number of characters
                // decreases then we decrease the size of curr_mpp_has have
                // value
                char ch = s[left];
                window_mpp[ch]--;

                // This checks if the number of values are decreased then the
                // have decreases
                if (mpp.find(ch) != mpp.end() && mpp[ch] > window_mpp[ch]) {
                    curr_mpp_has--;
                }
                left++;
            }
        }
        if (mini == INT_MAX) {
            return "";
        }
        // This will return the substring that starts from the minimum window
        // starting index and ends with the length of minimum substring
        return s.substr(min_starting, mini);
    }
};
