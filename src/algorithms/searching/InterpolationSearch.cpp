// Interpolation Search is an improvement over Binary Search for uniformly distributed sorted arrays. It uses the value of the target element to estimate the position of the search. 

#include "../include/algorithms/searching/InterpolationSearch.h"

int interpolationSearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right && target >= arr[left] && target <= arr[right])
    {
        int pos = left + ((right - left) / (arr[right] - arr[left])) * (target - arr[left]);
        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return -1; // Target not found
}