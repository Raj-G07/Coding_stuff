// Function to find the nth Fibonacci number 
#include "./matrix_exponentiation.cpp"

long long findFibonacci(long long n, int MOD) { 
    if (n == 0) return 0; 
    Matrix F = {{1, 1}, {1, 0}}; 
    Matrix result = matrixExpo(F, n - 1, MOD); 
    return result[0][0];
}