/*
 * author: greyshell
 * description: find the 5th fibonacci number
 * if n = 7 then output = 13
 * considering 0th fib = 0, 1st fib = 1
 * */

#include <stdio.h>

size_t fib(size_t n) {
    /*
     * property:
     * ==========
     * - recursive solution
     * - recurrent relation: F(n) = F(n-1) + F(n-2), seed values F(0) = 0 and F(1) = 1
     *
     * time complexity:
     * ===============
     * - actual program: time complexity = O(2^n)
     * - due to DP, time complexity reduced to O(n) for only having few fib(n-1) call
     *
     * space complexity:
     * =================
     * - O(n) -> max size of the call stack
     * - O(n) -> dp array size
     */
    // TO DO: dynamically generates the array based on the input.
    size_t dp[10] = {0};  // initialized with 0

    // pick the saved value -> O(1), greater than zero means it filled up earlier
    if (dp[n] > 0) {
        return dp[n];  // bug: when n > 9, the unallocated memory will be overwritten with fib number
    }
    // base case 1
    if (n == 0) {
        return 0;
    }
    // base case 1
    if (n == 1) {
        return 1;
    }

    // normal recursive call where value is not seen
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main(void) {
    // sample test case
    size_t number = 7;
    // function call
    printf("\n%zu th fib number = %zu", number, fib(number));
    return 0;
}