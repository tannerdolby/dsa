#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

// 347. https://leetcode.com/problems/top-k-frequent-elements/

// O(n log(k)) time O(n log(k)) space
vector<int> topKFrequent(vector<int>& nums, int k) {

    // list of k most frequent
    vector<int> frequentElems;
    
    // max heap
    priority_queue<pair<int,int>> pq;
    
    // frequency table
    unordered_map<int, int> frequencies;
    
    // populate frequency table
    for (int num : nums) {
        frequencies[num]++;
    }
    
    // populate priority queue with frequency pairs
    for (auto pair : frequencies) {
        std::pair<int,int> p = {pair.second, pair.first};
        pq.push(p);
    }
    
    // append the k most frequent values to resultant list
    while (!pq.empty() && k != 0) {
        frequentElems.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    
    return frequentElems;
}