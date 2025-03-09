/*The question stated is as following
-["a","a","b","b","c","c","c"] this needs to be changed as
["a","2","b","2","c","3"] -If the occurence of an element is only once then
there is no need to print "1"
*/
// Approaching out
// 1-continuous time which character is occuring out
// 2-the loops iterator is busy tracking down the occurence, we need one more
// index tracker for placements of the count as string

class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int index = 0;

        for (int i = 0; i < chars.size();) {
            char curr_char = chars[i];
            int count = 0;

            while (i < chars.size() && chars[i] == curr_char) {
                count++;
                i++;
            }
            // Post increment
            if (count == 1) {
                chars[index++] = curr_char;
            } 
            else {
                chars[index++] = curr_char;
                string countstring = to_string(count);
                for (char digit : countstring) {
                    chars[index++] = digit;
                }
            }
        }
        return index;
    }
};
