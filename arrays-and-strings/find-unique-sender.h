#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Given points Example1: (1,2),(0,1),(2,3),(5,6),(4,5) 
// where left one is sender and right one is receiver. 
// Find all the unique sender. 
// The answer for above is (0,4). 
// Since, first it got originated from 0->1->2->3 and 4->5->6.

vector<int> findUniqueSender(vector<vector<int>> arr) {
    unordered_set<int> uniqueReceivers;
    for (auto pair : arr) {
        uniqueReceivers.insert(pair[1]);
    }
    vector<int> uniqueSender;
    for (int i=0; i < arr.size(); i++) {
        if (uniqueReceivers.find(i) == uniqueReceivers.end()) {
            uniqueSender.push_back(i);
        }
    }
    return uniqueSender;
}