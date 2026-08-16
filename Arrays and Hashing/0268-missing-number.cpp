/*
 Problem: 0268 - Missing Number
 Difficulty: Easy
 Approach: Expected Summation - Actual Summation
 Time Complexity: O(n)
 Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, missingNum ;
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2; // Instant calculation using sum of n natural numbers formula
        for (int num:nums){
            sum+=num;
        }
        missingNum= expectedSum-sum ;
     return  missingNum ;
    }
};

/*
SOLUTION WHICH USES SUMMATION USING LOOP

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n, i, expectedSum = 0, sum = 0, missingNum ;
        n=nums.size();
        for (i=0;i<=n;i++){
            expectedSum+=i;
        }
        for (int num:nums){
            sum+=num;
        }
        missingNum= expectedSum-sum ;
     return  missingNum ;
    }
};

*/