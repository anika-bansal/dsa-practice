/*
 Problem: 1365 - How Many Numbers Are Smaller Than the Current Number
 Difficulty: Easy
 Approach: Sorting and Hash Map 
 Time Complexity: O(n)
 Space Complexity: O(1)
 */

#include <unordered_map>
#include <vector> 
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int i, n;
        n= nums.size();
        vector <int> temp;
        temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map <int,int> smallMap;
        for (i=0;i<n;i++){
         if (smallMap.contains(temp[i])){
            continue;
         }
        smallMap [temp[i]]=i;
        }

        vector <int> resultList;
        for (int num: nums){
            resultList.push_back(smallMap[num]) ;
        }
        return resultList;
        

    }
};