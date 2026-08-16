/*
 Problem: 0001 - Two Sum
 Difficulty: Easy
 Approach: Hash Map
 Time Complexity: O(n)
 Space Complexity: O(n)
 */

#include <unordered_map>
#include <vector> 
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sumMap;

        for (int i=0; i< nums.size(); i++){
         int diff = target - nums[i];

         if (sumMap.find(diff)!=sumMap.end()){
          return {sumMap[diff],i}; //returns the index of the complement and of the og number
         }

         sumMap[nums[i]]=i; //populating hash map one at a time
        }
        return{};
    }
};

/* BRUTE FORCE/INITIAL SOLUTION
 Time Complexity: O(n²)
 Space Complexity: O(1)

#include <vector> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++ ){
                if (nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
         return{};
    }
};
*/