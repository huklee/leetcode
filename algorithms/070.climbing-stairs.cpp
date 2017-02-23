class Solution {
public:
    int climbStairs(int n) {
        int f1=1, f2=2, f3=3;
        if (n == 1) return f1;
        else if (n == 2)    return f2;
        for (int i=0; i < n-2; i++){
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
};
