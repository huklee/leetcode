class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_table;
        int starti=0, endi=0, max_index=0;
        while (endi < s.size()){
            if (hash_table.find(s.at(endi)) == hash_table.end()){
                // 01. go forward adding a hash_table    
                hash_table[s.at(endi++)] = 1;
                if (endi - starti > max_index)
                    max_index = endi - starti;    
            }   
            else{
                // 02. go backward deleting a hash_table
                while (starti < endi){
                    if (s.at(starti) != s.at(endi))
                        hash_table.erase(s.at(starti++));
                    else{
                        starti++;
                        break;
                    }   
                }   
                endi++;
            }   
        }   
    return max_index;
    }
};
