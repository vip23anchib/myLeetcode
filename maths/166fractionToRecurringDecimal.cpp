class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        // Convert to long long so calculations are safer
        long long num = numerator;
        long long den = denominator;

        // If numerator is 0, answer is simply "0"
        if (num == 0) {
            return "0";
        }

        // This string will store our final answer
        string ans = "";

        // If exactly ONE of numerator/denominator is negative,
        // the answer should be negative.
        // ^ means XOR (exactly one is true)
        if ((num < 0) ^ (den < 0)) {
            ans += "-";
        }

        // Remove negative signs.
        // llabs() gives the absolute value of a long long.
        num = llabs(num);
        den = llabs(den);

        // Get the part before the decimal point.
        // Example: 7 / 2 = 3
        ans += to_string(num / den);

        // Get the remainder.
        // Example: 7 % 2 = 1
        long long rem = num % den;

        // If remainder is 0, division was exact.
        // Example: 6 / 2 = 3
        if (rem == 0) {
            return ans;
        }

        // There is a decimal part
        ans += ".";

        // Store:
        // remainder -> position where this remainder first appeared
        //
        // We use this to detect repeating decimals.
        unordered_map<long long, int> mp;

        // Continue calculating digits after decimal
        while (rem != 0) {

            // If we have already seen this remainder,
            // the decimal digits from that point will repeat.
            if (mp.count(rem)) {

                // Put '(' at the position where
                // this repeating sequence started
                ans.insert(mp[rem], "(");

                // Put ')' at the end
                ans += ")";

                break;
            }

            // Remember where this remainder appeared
            mp[rem] = ans.size();

            // Multiply remainder by 10
            // This is how we get the next decimal digit
            rem *= 10;

            // Get the next digit
            int digit = rem / den;

            // Add that digit to our answer
            ans += to_string(digit);

            // Get the new remainder
            rem %= den;
        }

        // Return the final decimal representation
        return ans;
    }
};
