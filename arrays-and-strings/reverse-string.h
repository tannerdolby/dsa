#include <iostream>
#include <vector>
using namespace std;

// Iterative
// O(n) time and O(1) space
void reverseString(vector<char>& s) {
    int left = 0, right = s.size()-1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return;
}

// Recursive
// O(n) time and O(n) space
// space is due to the frames on call stack from recursive calls
void reverseStr(vector<char>& s) {
    reverseHelper(s, 0, s.size()-1);
}

void reverseHelper(vector<char>& s, int l, int r) {
    if (l >= r) return;
    swap(s[l], s[r]);
    reverseHelper(s, l+1, r-1);
}