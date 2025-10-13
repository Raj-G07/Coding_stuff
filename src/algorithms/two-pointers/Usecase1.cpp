// Finding Pairs That Sum to a Target in a Sorted Array

#include <iostream>
#include <vector>

using namespace std;

bool findPairWithSum(const vector<int> &arr, int targetSum) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == targetSum) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")\n";
            return true;
        } else if (currentSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }
    cout << "No pair found\n";
    return false;
}