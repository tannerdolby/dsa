#include <iostream>
using namespace std;

// 125. Valid Palindrome: https://leetcode.com/problems/valid-palindrome/

/// Approach
// 1. Iterate the input string `s` and append only the alpha-numeric characters 
// to a resultant string `palindrome`
// 2. Check if the filtered string is a palindrome

class Solution {
public:
    // Iterative approach
    // O(n) time and O(1) space
    bool isPalindrome(string s) {
        string palindrome = "";
        for (int i=0; i < s.length(); i++) {
            if (!isalnum(s[i])) continue;
            palindrome += tolower(s[i]);
        }
        return isPalindromeHelper(palindrome);
    }
    
    bool isPalindromeHelper(string s) {
        if (s.length() == 1) return true;
        int left = 0, right = s.length()-1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};