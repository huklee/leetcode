class Solution {
public:
    void swap(int &a, int &b){  int t = a;   a = b;  b = t;}
    void moveZeroes(vector<int>& nums) {
      int cnt_nonzero = 0;
      for (int i=0; i < nums.size(); i++){
        if (nums[i] != 0){
            if (i != cnt_nonzero)
                swap(nums[i], nums[cnt_nonzero]);
            cnt_nonzero++;
        }
      }
    }
};
