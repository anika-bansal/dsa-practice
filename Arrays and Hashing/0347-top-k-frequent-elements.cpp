/*
 Problem: 0347 - Top K Frequent Elements
 Difficulty: Medium
 Approach: Hash Table and Min Heap
 Time Complexity: O(n log k) 
 Space Complexity: O(n+k)
 where n = length of array and k = no. of top frequent elements (given)
 */

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> freqTable;
        for (int num: nums){
            freqTable[num]++;
        }     
        using freqNumPair = pair<int,int>;
        priority_queue<freqNumPair, vector<freqNumPair>, greater <freqNumPair>> minHeap; 

        for (const auto& [number,frequency]: freqTable){
            minHeap.push({frequency,number});

            if (minHeap.size()>k){
             minHeap.pop();
         }

        }

        vector <int> result;
        while (!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
    
        return result;

    }
};