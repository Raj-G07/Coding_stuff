#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right);
void mergeSort(vector<int> &arr, int left, int right);

#endif // MERGE_SORT_H

// Time Complexity: 
// Best, Average, and Worst Case: O(nlog⁡n) 
// Space Complexity: O(n) 