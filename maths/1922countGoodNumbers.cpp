// ===================== LEETCODE 1922 =====================
//
// COUNT GOOD NUMBERS
//
// A digit string is GOOD if:
//
// 1. Digits at EVEN indices must be EVEN.
// 2. Digits at ODD indices must be PRIME.
//
// Indices are 0-based:
//
// index:  0   1   2   3   4   5
//         E   O   E   O   E   O
//
// EVEN digits:
// 0, 2, 4, 6, 8
// => 5 choices
//
// PRIME digits:
// 2, 3, 5, 7
// => 4 choices
//
// Therefore:
//
// answer = 5^(number of even indices)
//        * 4^(number of odd indices)
//
// ---------------------------------------------------------
//
// Number of EVEN indices:
//
// n = 5
// indices: 0 1 2 3 4
//          E O E O E
//
// even = 3
//
// Formula:
// even = (n + 1) / 2
//
// Number of ODD indices:
//
// odd = n / 2
//
// ---------------------------------------------------------
//
// IMPORTANT:
// n can be VERY LARGE.
//
// So we cannot do:
//
// for(i = 0; i < n; i++)
//
// because that would take O(n).
//
// We also cannot directly calculate:
//
// pow(5, even)
//
// because the number becomes enormous.
//
// Therefore we use FAST POWER:
//
// fastPower(5, even)
// fastPower(4, odd)
//
// ---------------------------------------------------------
//
// MOD:
//
// The problem itself says:
//
// return answer modulo 10^9 + 7
//
// 10^9 + 7 = 1000000007
//
// We are NOT choosing this value ourselves.
// It is given by the problem.
//
// Taking % MOD keeps numbers manageable.
//
// ---------------------------------------------------------

class Solution {
public:

    // MOD is given directly in the problem.
    const long long MOD = 1000000007;

    // Calculates (a^b) % MOD
    // Time: O(log b)
    // Space: O(1)
    long long fastPower(long long a, long long b)
    {
        long long ans = 1;

        while(b > 0)
        {
            // If b is odd, multiply current power into answer.
            if(b % 2 == 1)
            {
                ans = (ans * a) % MOD;
            }

            // Square the base.
            a = (a * a) % MOD;

            // Reduce exponent by half.
            b = b / 2;
        }

        return ans;
    }


    int countGoodNumbers(long long n)
    {
        // Number of positions with EVEN indices:
        // 0, 2, 4, 6, ...
        //
        // Formula:
        // (n + 1) / 2
        long long even = (n + 1) / 2;


        // Number of positions with ODD indices:
        // 1, 3, 5, 7, ...
        //
        // Formula:
        // n / 2
        long long odd = n / 2;


        // Every EVEN index has 5 possible digits:
        // 0, 2, 4, 6, 8
        //
        // Therefore:
        // 5^even
        long long evenWays = fastPower(5, even);


        // Every ODD index has 4 possible digits:
        // 2, 3, 5, 7
        //
        // Therefore:
        // 4^odd
        long long oddWays = fastPower(4, odd);


        // Multiply the possibilities.
        //
        // Total:
        // 5^even * 4^odd
        //
        // Take modulo because answer can be extremely large.
        return (evenWays * oddWays) % MOD;
    }
};
