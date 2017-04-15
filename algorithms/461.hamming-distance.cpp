class Solution {
public:
    int hammingDistance(int x, int y) {
        return sparse_bit(x^y);
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
