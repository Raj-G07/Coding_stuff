//  Searching in a 2D Matrix

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int left = 0, right = n * m - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int r = mid / m, c = mid % m;
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] > target)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return false;
}