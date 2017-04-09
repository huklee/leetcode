class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        return sparse_bit(z);
    }
    
    int sparse_bit(int x){
        int count = 0;
        while (x){
            count++;
            x &= (x - 1);
        }
        return count;
    }
};
