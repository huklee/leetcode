class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i : nums){
            if (s.find(i) == s.end())
                s.emplace(i);
            else
                return true;
        }
        return false;
    }
    
    bool containsDuplicate_simple(vector<int>& nums) {
        return set<int>(nums.begin(), nums.end()).size() != nums.size(); 
    }
};
