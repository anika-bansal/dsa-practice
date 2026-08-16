/*
 Problem: 0242 - Valid Anagram
 Difficulty: Easy
 Approach: Frequency Array
 Time Complexity: O(n+m) // n = length of string s, and m = length of string t
 Space Complexity: O(1) //at most 26 different characters
 */
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











