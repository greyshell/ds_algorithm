#include <stdio.h>

/*
description: find the 5th fibonacci number
n = 5, output = 5, considering 0th fib = 0, 1st fib = 1

For seed values F(0) = 0 and F(1) = 1
F(n) = F(n-1) + F(n-2)

actual program: time complexity = O(2^n)
dp: time complexity = O(n) -> only due to fib(n-1) call
space complexity = O(k), size of the dp[arr]
*/

int fib(int);  // top down approach

int fib(int n) {
    static int dp[10];  // initialized with 0

    // pick the saved value -> O(1), greater than zero means it filled up earlier
    if (dp[n] > 0) {
        return dp[n];  // bug: when n > 9, the unallocated memory will be overwritten with fib number
    }
        // base case
    else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    // normal recursive call where value is not seen
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main() {
    // sample test case
    int number = 3;
    // function call
    printf("%d-th fib number= %d", number, fib(number));
    return 0;
}