#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &arr,int left, int right, int target);

#endif // BINARY_SEARCH_H

// Time Complexity:
// Best Case: O(1) - when the target is at the middle of the array
// Average and Worst Case: O(log n)
// Space Complexity: O(1)