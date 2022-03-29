#include <vector>
using namespace std;

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