class Solution {
public:
    const int INT_MAX_ = (1 << 31) - 1;
    const int INT_MIN_ = -(1 << 31);

    bool overflowSafeAdd(int a, int b){
        if (b > 0){
            if (a > INT_MAX_ - b)
                return false;   
        }
        else{
            if (a < INT_MIN_ - b)
                return false;
        }
        return true;
    }
    
    int overflowSafeMul(int a, int b){
        if (b == 0)     return true;
        if ((a > 0 && b > 0) || (a < 0 && b < 0)){
            if (a > INT_MAX_/b)
                return false;   
        }
        else{
            if (a < INT_MIN_/b)
                return false;
        }
        return true;
    }

    int solution1(int x) {      
        // 00. edge case
        if (x == -(1 << 31))    return 0;
        
        // 01. other cases
        int result = 0;
        while (x != 0){
            if (overflowSafeMul(result, 10) == false)
                return 0;
            result *= 10;
            
            if (overflowSafeAdd(result, x%10) == false)
                return 0;
            result += x % 10;
            x /= 10;
        }
        return result;
    }

	int solution2(int x){
        int result = 0, prev;
        while (x != 0){
            prev = result;
            result = result*10 + x % 10;
            
            // 01. check overflow
            if ((result - x%10)/10 != prev) 
                return 0;
            x /= 10;
        }
        return result;
	}

    int reverse(int x) {
		// return solution1(x)
		return solution2(x)
    }
};
