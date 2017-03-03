class Solution {
public:
    // DP approach : O(n)
    int maxProduct(vector<int>& nums) {
        // edge case
        if (nums.size() == 0)
            return 0;
            
        int g_max = nums[0], DP_max = nums[0], DP_min = nums[0];
        for (int i=1; i < nums.size(); i++){
            int _max = max(max(DP_max*nums[i], DP_min*nums[i]), nums[i]);
            int _min = min(min(DP_max*nums[i], DP_min*nums[i]), nums[i]);
            DP_max = _max;
            DP_min = _min;
            g_max = max(g_max, DP_max);
        }
        return g_max;
    }
};
