/*
 Problem: 0054 - Spiral Matrix 1
 Difficulty: Medium
 Approach: Direction Vectors
 Time Complexity: O(m*n)
 Space Complexity: O(m*n)
 where m = number of rows and n = number of columns
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        // Handling edge case: empty matrix
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Defining direction vectors in clockwise order 
        // Right (0, 1), Down (1, 0), Left (0, -1), Up (-1, 0)
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Initializing our capacity constraints 
        // steps[0] tracks horizontal capacity, steps[1] tracks vertical capacity 
        int steps[2] = {cols, rows - 1};

        // Starting position: just outside the matrix to the left 
        int r = 0;
        int c = -1;
        int d = 0; // Starting direction index: Right 

        vector<int> result;

        //Keep moving as long as the current direction's step allowance > 0
        while (steps[d & 1] > 0) { //d&1 checks if current direction are horizontal or vertical ->alows it to access remaining col.s and rows
            int moves = steps[d & 1]; // how many steps to take this round
            
            for (int i = 0; i < moves; ++i) {
                r += dirs[d].first;  // updating row by accessing [d] index of dirs, and using first coordinate
                c += dirs[d].second; // updating column by accessing [d] index of dirs, and using second coordinate
                result.push_back(matrix[r][c]); // grabbing our element 
            }

            // Shrinking the step count for this dimension (reducing no. of the columns or rows left to traverse )
            steps[d & 1]--;

            // Turning to the next direction clockwise 
            d = (d + 1) % 4;
        }

        return result;
    }
};