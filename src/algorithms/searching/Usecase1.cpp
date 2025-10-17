// Binary Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

int binarySearchInRotatedArray(const vector<int> &arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[left] <= arr[mid])
        {
            if (arr[left] <= target && arr[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        else
        {
            if (arr[mid] < target && arr[right] >= target)
            {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
    }
    return -1;
}

// Time Complexity:
// Best Case: O(1)
// Worst Case: O(logn)
// Space Complexity: O(1)