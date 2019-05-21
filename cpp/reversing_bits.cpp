#define NUM_BITS (32)

class Solution {
public:

    uint32_t reverseBits(uint32_t n) {     
        uint32_t result = 0;
        char bit = 0;
        for(int i= 0; i < NUM_BITS; ++i)
        {
            bit = (n>>i) & 1;
            result = (result << 1) | bit;
        }
        return result;
    }
};
