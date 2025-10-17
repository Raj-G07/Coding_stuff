#ifndef INTERPOLATION_SEARCH_H
#define INTERPOLATION_SEARCH_H

#include <iostream>
#include <vector>

using namespace std;

int interpolationSearch(const vector<int> &arr,int target);

#endif // INTERPOLATION_SEARCH_H

// Time Complexity:
// Best Case: O(1) - when the target is at the middle of the array
// Average and Worst Case: O(log n)
// Space Complexity: O(1)