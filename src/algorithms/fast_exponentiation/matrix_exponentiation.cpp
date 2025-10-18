// Matrix exponentiation is a powerful technique to compute powers of a matrix efficiently. It is widely used in problems that involve recurrence relations, such as Fibonacci sequence calculations, linear recurrence relations, and solving systems of linear equations. 


#include <iostream> 
#include <vector> 
using namespace std; 
// Define a type for matrices 
typedef vector<vector<long long>> Matrix; 

Matrix multiply(const Matrix &A, const Matrix &B, int MOD) {
    int n = A.size(); 
    Matrix C(n, vector<long long>(n, 0)); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            for (int k = 0; k < n; k++) { 
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD; 
            } 
        } 
    } 
    return C;   
}

Matrix matrixExpo(Matrix A, long long n, int MOD) {
    int size = A.size(); 
    Matrix result(size, vector<long long>(size, 0)); 
    for (int i = 0; i < size; i++) 
        result[i][i] = 1; // Identity matrix 

    while (n > 0) { 
        if (n % 2 == 1) { 
            result = multiply(result, A, MOD); 
        } 
        A = multiply(A, A, MOD); 
        n /= 2; 
    } 
    return result;
}

// Time Complexity 
// Matrix Multiplication: O(k^3), where k is the size of the matrix.
// Exponentiation by Squaring: O(logn). 
// Total Time Complexity: O(k^3⋅logn).
// For the Fibonacci sequence (k=2), this simplifies O(logn).