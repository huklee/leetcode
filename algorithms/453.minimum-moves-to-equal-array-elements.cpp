class Solution {
public:
    int minMoves(vector<int>& v) {
        int sum = 0, min_val = (1 << 31) - 1;
        for (int i=0; i < v.size(); i++){
            sum += v[i];
            min_val = min(min_val, v[i]);
        }
        return sum - v.size()*min_val;
    }
};
