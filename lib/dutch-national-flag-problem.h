#include <vector>
using namespace std;

/*
 - https://en.wikipedia.org/wiki/Dutch_national_flag_problem
 - 75. Sort Colors: https://leetcode.com/problems/sort-colors/
*/

void sortColors(vector<int>& nums) {
    int left = 0, curr = 0, right = nums.size()-1;
    while (curr <= right) {
        if (nums[curr] == 0) {
            swap(nums[curr], nums[left]);
            left++;
            curr++;
        } else if (nums[curr] == 1) {
            curr++;
        } else if (nums[curr] == 2) {
            swap(nums[curr], nums[right]);
            right--;
        }
    }
}