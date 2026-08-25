// 191 : Number Of 1 bits

// Given a positive integer n, write a function that returns the number of set bits in its binary representation 
// (also known as the Hamming weight).

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;

        while(n > 0) {
            
            if(n % 2 == 1) {
                count++;
            }

            n = n / 2;
        }

        return count;
    }
};

//OR

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;

        while(n > 0) {
            
            if(n & 1) {
                count++;
            }

            n = n >> 1;
        }

        return count;
    }
};
