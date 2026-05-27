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

         sumMap[nums[i]]=i;
        }
        return{};
    }
};