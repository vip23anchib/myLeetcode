// ===================== FAST POWER / BINARY EXPONENTIATION =====================

// Used to calculate: (a^b) % MOD
//
// Normal power:
// a^b = a * a * a * ... b times
//
// Normal approach takes O(b) time.
//
// Fast Power reduces this to O(log b)
// by:
// 1. Checking whether b is odd
// 2. Squaring a
// 3. Dividing b by 2
//
// Example:
// 2^10
//
// Instead of:
// 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
//
// We use:
// 2^10 = 2^8 * 2^2
//
// We get powers by repeatedly squaring:
// 2^1 -> 2^2 -> 2^4 -> 2^8 -> 2^16 ...

long long fastPower(long long a, long long b)
{
    long long ans = 1;

    while(b > 0)
    {
        // If b is ODD, current 'a' is needed in our answer.
        //
        // Example:
        // b = 5
        // 5 = 4 + 1
        // So we need a^1 in the answer.
        if(b % 2 == 1)
        {
            ans = (ans * a) % MOD;
        }

        // Square the base.
        //
        // a^1 -> a^2
        // a^2 -> a^4
        // a^4 -> a^8
        // a^8 -> a^16
        a = (a * a) % MOD;

        // Divide exponent by 2.
        //
        // This is what makes the algorithm FAST.
        b = b / 2;
    }

    return ans;
}

// Time Complexity: O(log b)
// Space Complexity: O(1)
