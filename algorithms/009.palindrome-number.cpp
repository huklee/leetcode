class Solution {
public:
    bool isPalindrome(int x) {
        // by definition, all negative numbers are non-palindrome
    	if (x < 0)
    		return false;

        // initialization : c is the biggest digit divider
    	int c = 1;
    	while (x/c >= 10)
    		c *= 10;
    	
    	while (c >= 10){
    	    // check the first & last digist of x
    		if (x%10 != x/c)
    			return false;
		    
		    // cut the first & last digit of x
    		x = (x%c)/10;
    		c /= 100;
    	}
    	return true;
    }
};
