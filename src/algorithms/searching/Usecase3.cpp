//  Square Root of a Number

#include <iostream>

int findSquareRoot(int n)
{
    int left = 0;
    int right = n;
    int ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ans;
}