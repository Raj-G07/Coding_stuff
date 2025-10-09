// Binary Search is a classic searching algorithm used to find an element in a sorted array by repeatedly dividing the search interval in half. It compares the target element with the middle element of the array and discards half of the search space.

#include "../include/algorithms/searching/BinarySearch.h"
using namespace std;

int binarySearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

