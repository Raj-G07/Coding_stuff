// The Extended Euclidean Algorithm not only finds the GCD of two numbers but 
// also computes coefficients x and y such that: 
// ax+by=GCD(a,b) 

#include<iostream>
using namespace std;

// Function to implement Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    // Base Case
    if (a == 0) {
        x = 0;
        y = 1;  
        return b;
    }
    int gcd = extendedGCD(b % a, a, y, x);
    y -= (b / a) * x;
    return gcd;
}