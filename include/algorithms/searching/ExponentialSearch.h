#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int exponentialSearch(const vector<int> &arr, int target);

#endif 

// Time Complexity: 
// Best Case: O(1) (if the element is found early) 
// Worst Case: O(logn), where nnn is the number of elements. 
// Space Complexity: O(1) 