#include <iostream>
#include <vector>
using namespace std;

// Approach: 
// 1. Populate a frequency table from the magazine string 
// (using a hash map with unordered_map<char,int> 
// or using less space with a vector<int>(26))
// 2. Iterate the ransomNote and decrement character counts
// when we encounter a character in magazine
// 3. If we encounter a character frequency that is less than
// or equal to 0, this means we are attempting to overdraw a character or it never existed in magazine to begin with, meaning return false
// 4. Otherwise if step 3 isn't the case, return true

// string using a hash map then decrement characters

// O(n) time and O(1) space
bool canConstruct(string ransomNote, string magazine) {
    if (ransomNote.length() > magazine.length()) return false;
    
    vector<int> chars(26);
    
    for (char ch : magazine) {
        chars[ch - 'a']++;
    }
    
    for (char ch : ransomNote) {
        if (chars[ch - 'a'] <= 0) return false;
        chars[ch - 'a']--;
    }

    return true;
}