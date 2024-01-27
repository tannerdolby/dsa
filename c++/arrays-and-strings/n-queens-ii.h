// 52. N-Queens II
// https://leetcode.com/problems/n-queens-ii/

#include <unordered_set>
using namespace std;

class Solution {
private:
    int size;
    
    bool isQueenPlaceable(int col, int currDiagonal, int currAntiDiagonal, unordered_set<int> diagonals, unordered_set<int> antiDiagonals, unordered_set<int> cols) {
        if (cols.find(col) != cols.end() ||
            diagonals.find(currDiagonal) != diagonals.end() ||
            antiDiagonals.find(currAntiDiagonal) != antiDiagonals.end()
           ) {
                return true;
            }
        return false;
    }
    
    void placeQueen(int col, int currDiagonal, int currAntiDiagonal, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols) {
        cols.insert(col);
        diagonals.insert(currDiagonal);
        antiDiagonals.insert(currAntiDiagonal);
        return;
    }
    
    void removeQueen(int col, int currDiagonal, int currAntiDiagonal, unordered_set<int>& diagonals, unordered_set<int>& antiDiagonals, unordered_set<int>& cols) {
        cols.erase(col);
        diagonals.erase(currDiagonal);
        antiDiagonals.erase(currAntiDiagonal);
        return;
    }
    
    int backtrack(int row, unordered_set<int> diagonals, unordered_set<int> antiDiagonals, unordered_set<int> cols) {
        // base case - N queens have been placed
        // if we are past the last row of the grid
        // all solutions have been explored
        if (row == size) return 1;
        
        int solutions = 0;
        for (int col=0; col < size; col++) {
            // attacking diagonals
            int currDiagonal = row - col;
            int currAntiDiagonal = row + col;
            
            // is queen placeable? i.e. not under attack
            if (isQueenPlaceable(col, currDiagonal, currAntiDiagonal, diagonals, antiDiagonals, cols)) {
                continue;
            }
            
            // add queen to the board as its placeable!
            // (i.e. place queen on the board as its not attackable)
            placeQueen(col, currDiagonal, currAntiDiagonal, diagonals, antiDiagonals, cols);
            
            // move onto the next row with the updated board state
            // to begin checking the row for placeable queens
            solutions += backtrack(row+1, diagonals, antiDiagonals, cols);
            
            // remove queen from the board since we have already
            // explored all valid paths (all possible solutions)
            removeQueen(col, currDiagonal, currAntiDiagonal, diagonals, antiDiagonals, cols);
        }
        return solutions;
    }
public:
    
    // O(N!) time and O(N) space where N is the number of queens
    // which is also the same number of rows and columns in the grid
    int totalNQueens(int n) {
        size = n;
        return backtrack(0, unordered_set<int>(), unordered_set<int>(), unordered_set<int>());
    }
    
};