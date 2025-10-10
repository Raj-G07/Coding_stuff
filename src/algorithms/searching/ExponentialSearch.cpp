#include "../include/algorithms/searching/ExponentialSearch.h"
#include "../include/algorithms/searching/BinarySearch.h"

int exponentialSearch(const vector<int> &arr, int target)
{
    if (arr[0] == target)
        return 0;
    int i = 1;
    while (i < arr.size() && arr[i] < target)
        i *= 2;
    int size = arr.size() - 1;
    return binarySearch(arr, i / 2, min(i, size), target);
}