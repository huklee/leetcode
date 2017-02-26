class Solution {
public:
    // O(n) solution with 32 bits
    int singleNumber(vector<int>& nums) {
        // bit summation & mod 3 operations
        int bits[32] = {0,};
        for (int i=0; i < nums.size(); i++){
            for (int j=0; j < 32; j++){
                int mask = 1<<j;
                int add_bit = (nums[i]&mask) ? 1 : 0;
                bits[j] = (bits[j] + add_bit)%3;
            }
        }
                
        // covert bits -> digial number
        int num = 0;
        for (int j=0; j < 32; j++)
            num += (1 << j)*bits[j];
        return num;
    }
};
