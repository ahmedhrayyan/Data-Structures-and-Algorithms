#include <iostream>
#include <cassert>
#include <vector>
#include "AlgorithmicToolbox.h"

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    if (n <= 1) return n;

    std::vector<long long> arr(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int last_fibonacci_num(int n) {
    if (n <= 1) return n;

    int arr[61] = {};
    arr[0] = 0;
    arr[1] = 1;

    /* calculate the last digit of the first 60 fibonacci numbers, as the last digit of fibonacci numbers is a series
    with a cycle length of 60 */
    for (int i = 2; i <= 60; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
    }

    return arr[n % 60];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
    {
        assert(fibonacci_fast(n) == fibonacci_naive(n));
        assert(fibonacci_fast(n) % 10 == last_fibonacci_num(n));
    }
}
