// Exponentiation by Squaring (For powers) 

#include "algorithms/fast_exponentiation/exponentiation_by_squaring.h"

long long exp_by_squaring(long long x, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1) { // If n is odd
            result *= x;
        }
        x *= x; // Square the base
        n /= 2; // Divide n by 2
    }
    return result;
}