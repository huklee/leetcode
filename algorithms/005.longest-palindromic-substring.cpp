class Solution {
public:
    string longestPalindrome(string s) {
        // 01. set the mid point
        if (s == "")    return "";
        int n = s.size(), max_strlen = 1;
        string max_str = s.substr(0,1);
        for (int mid=0; mid < n; mid++){
            int max_len = min(mid, n - 1 - mid);
            // 02-1. max odd mid palindrome
            for (int j=0; j <= max_len; j++){
                if (s[mid - j] != s[mid + j])   break;
                else if (1 + 2*j > max_strlen){
                    max_strlen = 1 + 2*j;
                    max_str = s.substr(mid - j, 1 + 2*j);
                }
            }
            
            // 02-2. max even mid palindrome
            max_len = min(mid, n - 2 - mid);
            for (int j=0; j <= max_len; j++){
                if (s[mid - j] != s[mid + 1 + j])   break;
                else if (2 + 2*j > max_strlen){
                    max_strlen = 2 + 2*j;
                    max_str = s.substr(mid - j, 2 + 2*j);
                }
            }
        }
        return max_str;
    }
};
