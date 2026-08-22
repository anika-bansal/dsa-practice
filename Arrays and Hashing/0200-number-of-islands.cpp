/*
 Problem: 0200 - Number of Islands
 Difficulty: Medium
 Approach: BFS
 Time Complexity: O(m*n) 
 Space Complexity: O(m*n)
 where m = number of rows and n = number of columns
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        // Direction vectors for moving: Up, Down, Left, Right
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // When we find an unvisited land cell ('1')
                if (grid[r][c] == '1') {
                    count++;
                    grid[r][c] = '0'; // Mark as visited directly in the grid
                    
                    queue<pair<int, int>> q;
                    q.push({r, c});

                    // BFS to visit all connected land cells
                    while (!q.empty()) {
                        auto [currRow, currCol] = q.front();
                        q.pop();

                        for (const auto& [dr, dc] : directions) {
                            int nr = currRow + dr;
                            int nc = currCol + dc;

                            // Check grid boundaries and if the neighbor is land ('1')
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                grid[nr][nc] = '0'; // Mark as visited when adding to queue
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};