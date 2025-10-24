// The Greatest Common Divisor (GCD) of two integers a and b is the largest number that divides both a and b without leaving a remainder. It is a fundamental concept in number theory and is commonly used in problems involving fractions, divisibility, and modular arithmetic.

#include <iostream>
using namespace std;
// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}