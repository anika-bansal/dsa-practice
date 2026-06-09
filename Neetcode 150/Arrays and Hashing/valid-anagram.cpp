//Frequency Array
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: If lengths are different, they cannot be anagrams
        if (s.length() != t.length()) return false;
        
        // Step 2: Initialize a frequency array of size 26 with all zeros
        int count[26] = {0}; 
        
        // Step 3: Count frequencies by incrementing for s and decrementing for t
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Add character from s
            count[t[i] - 'a']--; // Remove character from t
        }
        
        // Step 4: Check if the array is perfectly balanced (all zeros)
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false; // Found a mismatch in frequency
            }
        }
        
        return true; // Everything balanced out perfectly
    }
};

/* Incorrect, as unordered sets condenses duplicates
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()){
         return false;
        } 
        std::unordered_set<char> seen1 (s.begin(),s.end());
        std::unordered_set<char> seen2 (t.begin(),t.end());
        if(seen1==seen2){
            return true;
        }
        return false;

    }
};
*/









