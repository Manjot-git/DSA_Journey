//Note: checks whether a given n x n grid represents a valid knight’s tour in chess, where the knight moves in an L shape and must visit all cells in sequential order.

// Key Concepts:
// The knight moves in 8 possible directions.
// The grid contains numbers from 0 to n² - 1, where 0 is the starting position.
// The knight must follow the sequence from 0 → 1 → 2 → ... → n² - 1.

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal){

        //base-cases
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expVal){
            return false;
        }

        if(expVal == n * n -1){ // If we reached the last expected value, return true
            return true;
        }

        //8 possible moves
        int ans1 = isValid(grid, r-2, c+1, n, expVal+1);
        int ans2 = isValid(grid, r-1, c+2, n, expVal+1);
        int ans3 = isValid(grid, r+1, c+2, n, expVal+1);
        int ans4 = isValid(grid, r+2, c+1, n, expVal+1);
        int ans5 = isValid(grid, r+2, c-1, n, expVal+1);
        int ans6 = isValid(grid, r+1, c-2, n, expVal+1);
        int ans7 = isValid(grid, r-1, c-2, n, expVal+1);
        int ans8 = isValid(grid, r-2, c-1, n, expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8; 
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0); 
    }
};
