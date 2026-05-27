//Hash Map solution
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int x: nums){
            if (seen.find(x)!=seen.end()){
                return true;
            }
            seen.insert(x);
        }
        return false;
            }
        };

/* BRUTE FORCE/INITIAL SOLUTION
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
         for (int j=i+1;j<nums.size();j++){
          if (nums[i]==nums[j]){
            return true;
          }
         }
        }
    return false;
    }
};
*/