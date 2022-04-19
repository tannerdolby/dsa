#include <iostream>
#include <vector>
using namespace std;

// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

// O(n) time and O(1) space
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    vector<int> chars(26);
    
    for (int i=0; i < s.length(); i++) {
        chars[s[i] - 'a']++;
        chars[t[i] - 'a']--;
    };
    
    for (int frequency : chars) {
        if (frequency != 0) return false;
    }
    
    return true;
}