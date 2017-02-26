class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        assert(digits.size() > 0);
        bool carry_flag = true;
        int i;
        vector<int> result;
        
        // plus one process with flow digit
        for (i=digits.size() - 1; i >= 0; i--){
            if (digits[i] + 1 == 10)
                digits[i] = 0;
            else{
                digits[i]++;
                carry_flag = false;
                break;
            }
        }
        
        // additional digit 
        if (carry_flag)
            digits.insert(digits.begin(), 1);
            
        return digits;
    }
};
