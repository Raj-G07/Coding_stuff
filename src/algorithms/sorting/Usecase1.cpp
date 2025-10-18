// Merging Multiple Sorted Lists (or Arrays) 

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    
    priority_queue<int,vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < arrays.size(); ++i) {
       for(auto element:arrays[i]){
        minHeap.push(element);
       }
    }
    
    vector<int> mergedArray;
    
    while (!minHeap.empty()) {
        auto current = minHeap.top();
        minHeap.pop();
        
        mergedArray.push_back(current);
    }
    
    return mergedArray;
}

// Time Complexity: O(N log k) where N is total number of elements and k is number of arrays
// Space Complexity: O(N)