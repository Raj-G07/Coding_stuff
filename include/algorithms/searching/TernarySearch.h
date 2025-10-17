#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

#include <iostream>
#include <vector>

using namespace std;

int ternarySearch(const vector<int> &arr,int left, int right, int target);

#endif // TERNARY_SEARCH_H

// Time Complexity:
// Best Case: O(1)O(1)O(1) 
// Worst and Average Case: O(log⁡3n) ≈ O(logn)
// Space Complexity: O(1)