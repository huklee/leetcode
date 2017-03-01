class Solution {
public:
    // Binary search solution with O(logN) space
    int getMinBS(vector<int>& v, int s, int e){
        // base case
        if (s == e)
            return v[s];
            
        // recursive case
        if (v[s] < v[e])
            return v[s];
        else{
            int mid = (s + e)/2;
            return min(getMinBS(v, s, mid), getMinBS(v, mid + 1, e));
        }
    }
    
    int findMin_rec(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        else
            return getMinBS(nums, 0, nums.size() -1);
    }
    
    // binary search with O(1) space
    int findMin_iter(vector<int>& nums) {
        // edge case
        if (nums.size() == 0)
            return 0;
            
        int s = 0, e = nums.size() - 1;
        while (nums[s] > nums[e]){
            int mid = (s + e)/2;
            if (nums[s] > nums[mid])
                e = mid;
            else
                s = mid + 1;
        }
        return nums[s];
    }
    
    int findMin(vector<int>& nums) {
        return findMin_iter(nums);
    }
};
