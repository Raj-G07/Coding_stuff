// Maximum Sum of a Subarray of Fixed Size k

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int> &arr, int k) {
    if (arr.size() < k || k <= 0) return 0;

    int maxSum = 0, currentSum = 0;

    // Calculate the sum of the first 'k' elements
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }
    maxSum = currentSum;

    // Slide the window from start to end of the array
    for (int i = k; i < arr.size(); i++) {
        currentSum += arr[i] - arr[i - k]; // Add next element and remove the first element of the previous window
        maxSum = max(maxSum, currentSum);   // Update maxSum if currentSum is greater
    }

    return maxSum;
}
