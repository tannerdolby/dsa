#include <vector>
using namespace std;

// binary search
// O(log(n*m)) time and O(1) space
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    int left = 0, mid = 0, midVal = 0, right = m*n-1;
    while (left <= right) {
        mid = left + (right-left) / 2;
        midVal = matrix[mid / n][mid % n];
        if (target == midVal) {
            return true;
        } else if (target < midVal) {
            // search left half
            right = mid - 1;
        } else {
            // search right 
            left = mid + 1;
        }
    }
    return false;
}


// O(n+m) time and O(1) space
// top-right corner approach (relies on matrix being sorted)
// Efficient approach using two-pointers
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col  = matrix[0].size()-1;
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            row++;
        } else {
            col--;
        }
    }
    return false;  
}


// Naive
// O(n*m) time 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            if (matrix[i][j] == target) {
                return true;
            }
        }
    }
    return false;
}