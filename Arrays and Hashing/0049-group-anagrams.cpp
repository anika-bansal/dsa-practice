/*
 Problem: 0049 - Group Anagrams
 Difficulty: Medium
 Approach: Frequency Array and Hash Map
 Time Complexity: O(m*n) 
 Space Complexity: O(m)
 where m = number of strings and n = length of longest string
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // A map where the Key is a unique string representing letter counts,
        // and the Value is the list of anagram strings matching that count.
        unordered_map<string, vector<string>> anagramMap;
        
        for (const string& s : strs) {
            // Frequency count array of 26 zeros for the current string
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }
            
            // Converting the frequency array into a unique string key.
            // Example: "aba" becomes "2,1,0,0,..." (2 'a's, 1 'b')
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + ","; 
            }
            
            //Mapping the original string under its frequency key
            anagramMap[key].push_back(s);
        }
        
        // Collecting all clustered groups into final result vector
        vector<vector<string>> finalResult;
        for (auto const& pair : anagramMap) {
            finalResult.push_back(pair.second);
        }
        
        return finalResult;
    }
};