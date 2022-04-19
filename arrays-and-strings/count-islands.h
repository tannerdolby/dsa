#include <vector>
using namespace std;

// O(m * n) time and O(m * n) space
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int islands = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // do a linear scan of the 2d grid
    for (int row=0; row < m; row++) {
        for (int col=0; col < n; col++) {
            if (!visited[row][col] && grid[row][col] == '1') {
                // start a dfs, at each root node ('1') 
                // and increment island count
                countIslands(grid, row, col);
                islands++;
            }
        }
    }
    return islands;
}

// maintains visited cells in a separate list
void countIslands(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& vis) {
        int m = grid.size(), n = grid[0].size();
        // bounds check
        if (row < 0 || row >= m || col < 0 || col >= n || vis[row][col] || grid[row][col] == '0') {
            return;
        }
        
        // mark as visited
        vis[row][col] = true;
        
        // do dfs
        countIslands(grid, row+1, col, vis);
        countIslands(grid, row-1, col, vis);
        countIslands(grid, row, col+1, vis);
        countIslands(grid, row, col-1, vis);
        countIslands(grid, row+1, col+1, vis);
        countIslands(grid, row-1, col-1, vis);
        countIslands(grid, row+1, col-1, vis);
        countIslands(grid, row-1, col+1, vis);
    }

// mutates original grid
void countIslands(vector<vector<char>>& grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    // bounds check
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') {
        return;
    }
    
    // mark as visitied (flip the cell in original grid)
    // note: only if mutating the input grid is allowed
    // otherwise vector<vector<bool>> visited would be used
    grid[row][col] = '0';
    
    // do dfs (8-directionally) note: typically just 4-directional
    countIslands(grid, row+1, col);
    countIslands(grid, row-1, col);
    countIslands(grid, row, col+1);
    countIslands(grid, row, col-1);
    countIslands(grid, row+1, col+1);
    countIslands(grid, row-1, col-1);
    countIslands(grid, row+1, col-1);
    countIslands(grid, row-1, col+1);
}