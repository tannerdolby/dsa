#include <vector>
using namespace std;

// 88. Merge Sorted Array
// https://leetcode.com/problems/merge-sorted-array/

// O(n + m) time and O(m) space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // if nums2 is empty, then nothing to merge into nums1
    if (nums2.size() == 0) return;
    
    // copy of m
    vector<int> nums1Copy = nums1;
    
    // pointers
    int p1 = 0, p2 = 0;
    
    for (int i=0; i < m + n; i++) {
        // check if pointers are in bounds
        // and compare values to determine which number
        // is inserted into nums1
        if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
            nums1[i] = nums1Copy[p1];
            p1++;
        } else {
            // we know nums1Copy[p1] >= nums2[p2]
            nums1[i] = nums2[p2];
            p2++;
        }
    }
}

// Naive approach
// O(n+m * log(n+m)) time and O(log(n+m)) space
void mergeArr(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i=0; i < n; i++) {
        // offset i by m to merge nums2 into the end of nums1
        nums1[i + m] = nums2[i];
    }

    // then sort it with quick-sort
    // O(n log(n)) time and O(log(n)) space
    sort(nums1.begin(), nums1.end());
}