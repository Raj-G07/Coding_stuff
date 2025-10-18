// Inversion Count
#include<iostream>
#include<vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int inv_count = 0;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inv_count += (n1 - i); 
        }
    }

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    return inv_count;
}

int countInversions(vector<int>& arr, int left, int right) { 
   if(left>right) return 0;
   int mid = left + (right - left) / 2;
   int inv_count = 0;   
    inv_count+=countInversions(arr, left, mid);
    inv_count+=countInversions(arr, mid + 1, right);
    inv_count+=mergeAndCount(arr, left, mid, right);
    return inv_count;
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)