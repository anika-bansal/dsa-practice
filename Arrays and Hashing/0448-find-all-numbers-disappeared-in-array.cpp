/*
 Problem: 0448 - Find All Numbers Disappeared in an Array
 Difficulty: Easy
 Approach: Hash Set
 Time Complexity: O(n)
 Space Complexity: O(n)
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     int n, i;
     n=nums.size();
     unordered_set<int> seen;
     for (int x:nums){
        if (seen.find(x)!=seen.end()){
            continue;
        }
        seen.insert(x); //converting vector to set to ensure no duplicates
     }
     vector<int> finalResult;
     for (i=1;i<=n;i++){
        if(seen.contains(i))
         continue;
        else
         finalResult.push_back(i);  //iterating through the set, if no. not in set, added to vector finalResult
     }
     return finalResult;

    }
};