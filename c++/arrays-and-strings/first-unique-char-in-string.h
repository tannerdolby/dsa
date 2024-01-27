#include <iostream>
#include <vector>
using namespace std;

// 387. First Unique Character in a String
// https://leetcode.com/problems/first-unique-character-in-a-string/

// O(n) time and O(1) space
int firstUniqChar(string s) {
    vector<int> chars(26);
    
    for (char ch : s) {
        chars[ch - 'a']++;
    }
    
    for (int i=0; i < s.length(); i++) {
        if (chars[s[i] - 'a'] == 1) {
            return i;
        }
    }
    
    return -1;
}