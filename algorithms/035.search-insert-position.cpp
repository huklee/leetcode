class Solution {
public:

    // binary search solution : O(log(n))
    // recursive solution
    int solve_rec (vector<int>& nums, int target, int start, int end){
        // base case
        if (end - start == 0)
            return (target <= nums[start]) ? start: start + 1;
        else if (end - start == 1){
            if (target <= nums[start])
                return start;
            else if (target <= nums[start + 1])
                return start + 1;
            else
                return start + 2;
        }
        
        // recursive case
        int mid = (start + end)/2;
        if (target <= nums[mid])
            return solve_rec(nums, target, start, mid);
        else
            return solve_rec(nums, target, mid, end);
    }
    
    // binary search iterative solution
    int solve_iter(vector<int>& nums, int target){
        assert(nums.size() > 0);
        int L = 0, R = nums.size() - 1;
        while (L < R){
            int M = (L + R)/2;
            if (nums[M] < target)
                L = M + 1;
            else
                R = M;
        }
        // L == R
        if (nums[L] < target)
            return L + 1;
        else
            return L;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return solve_iter(nums, target);
    }
};
