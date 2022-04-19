#include <vector>
using namespace std;

/*
 - 11. Container With Most Water
 - https://leetcode.com/problems/container-with-most-water/
*/

// O(n) time and O(1) space
int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int area = 0;
    while (left < right) {
        int x = right - left;
        int y = min(height[left], height[right]);
        area = max(area, x * y);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return area;
}