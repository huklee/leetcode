class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int count = 0, i = 1;
        while (z){
            if (i & z)
                count++;
            z &= ~i;
            i <<= 1;
        }
        return count;
    }
};
