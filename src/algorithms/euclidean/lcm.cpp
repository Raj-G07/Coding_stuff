#include "./gcd.cpp"  // Assuming gcd function is defined in this file

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// The lcm function calculates the least common multiple of two integers a and b
// using the relationship between gcd and lcm: lcm(a, b) = (a / gcd(a, b)) * b.