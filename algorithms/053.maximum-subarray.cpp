class Solution {
public:
    // DP solution : O(n)
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
            
        int max_val = nums[0], DP;
        for (int i=0; i < nums.size(); i++){
            DP = (i == 0) ? nums[i] : max(DP + nums[i], nums[i]);
            max_val = max(DP, max_val);
        }
        return max_val;
    }
};
