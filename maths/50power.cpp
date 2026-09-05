// ================= LEETCODE 50: POW(x, n) =================
//
// Goal:
// Calculate x^n
//
// Example:
// x = 2, n = 5
//
// 2^5 = 2 * 2 * 2 * 2 * 2 = 32
//
// ----------------------------------------------------------
//
// NORMAL APPROACH:
//
// for(int i = 0; i < n; i++)
//     ans *= x;
//
// Time Complexity = O(n)
//
// Problem:
// n can be very large.
//
// ----------------------------------------------------------
//
// FAST POWER / BINARY EXPONENTIATION:
//
// Instead of multiplying n times,
// repeatedly SQUARE the base and DIVIDE the exponent by 2.
//
// Example:
//
// 2^8
//
// 2^1 -> 2^2 -> 2^4 -> 2^8
//
// Only a few operations are needed.
//
// Time Complexity = O(log n)
// ----------------------------------------------------------
//
// IMPORTANT IDEA:
//
// If n is ODD:
//     multiply current base into answer.
//
// If n is EVEN:
//     don't multiply yet.
//
// Every iteration:
//     base = base * base
//     n = n / 2
//
// ----------------------------------------------------------


class Solution {
public:

    double myPow(double x, int n) {

        // Convert n to long long.
        // Why?
        // Because INT_MIN = -2147483648.
        // If we do -n directly when n is INT_MIN,
        // int cannot store +2147483648.
        long long N = n;

        // If exponent is negative:
        // x^(-n) = 1 / x^n
        if(N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while(N > 0)
        {
            // If exponent is ODD,
            // multiply current base into answer.
            //
            // Example:
            // 5^3 = 5^2 * 5
            //
            // The extra 5 needs to be included.
            if(N % 2 == 1)
            {
                ans = ans * x;
            }

            // Square the base.
            //
            // x^1 -> x^2 -> x^4 -> x^8 -> ...
            x = x * x;

            // Divide exponent by 2.
            N = N / 2;
        }

        return ans;
    }
};
