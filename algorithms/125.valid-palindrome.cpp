class Solution {
public:
    void validate(int &pos, string &s, bool plus_dir){
        while (pos >= 0 && pos < s.size() && !isalnum(s.at(pos)))
            pos = (plus_dir) ? pos + 1 : pos - 1;
    }

	// two pointers solutions (start, end) : O(n)
    bool isPalindrome(string s) {
        int start = 0, end = s.size() -1;
        while (start < end){
            validate(start, s, true);
            validate(end, s, false);
            if (start < end && tolower(s.at(start)) != tolower(s.at(end)))
                return false;
            start++;
            end--;
        }
        return true;
    }
};
