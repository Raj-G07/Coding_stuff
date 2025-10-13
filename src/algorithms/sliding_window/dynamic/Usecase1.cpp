// Longest Subarray with Sum Less Than or Equal to Target 

#include <iostream>
#include <vector>

using namespace std;

int longestSubarrayWithSumAtMostK(const vector<int> &arr, int k) {
    int left = 0, currentSum = 0, maxLength = 0;

    for (int right = 0; right < arr.size(); right++) {
        currentSum += arr[right];

        while (currentSum > k && left <= right) {
            currentSum -= arr[left];
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}
