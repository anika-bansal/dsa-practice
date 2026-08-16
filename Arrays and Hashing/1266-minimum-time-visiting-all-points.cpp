/*
 Problem: 1266 - Minimum Time Visiting All Points
 Difficulty: Easy
 Approach: Utilising Diagonal Movement 
 Time Complexity: O(n)
 Space Complexity: O(1)
 */

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time=0;
        for (int i=1;i<points.size();i++){
            time += max(abs(points[i][0]-points[i-1][0]), abs(points[i][1]-points[i-1][1])); //min time is sum of min times between each consecutive pair of points, which in turn is the max b/w (x2-x1) and (y2-y1) for all consecutive point pairs

        }
        return time;
    }
};