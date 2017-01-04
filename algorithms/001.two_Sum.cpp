class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // // 1. O(n^2) solution
        // // Brute-force : pick the two number;
        // vector<int> answer = vector<int>();
        // for (int i=0; i < nums.size(); i++){
        //     int pivot = nums[i];
        //     for (int j=i + 1; j < nums.size(); j++){
        //         int sum = pivot + nums[j];
        //         if(sum == target){
        //             answer.push_back(i);
        //             answer.push_back(j);
        //             return answer;
        //         }
        //     }
        // }
        // return answer;
        
        // 2. O(n) solution
        // using hash table
        unordered_map<int, int> hash_table;
        vector<int> answer = vector<int>();
        for (int i=0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (hash_table.find(complement) != hash_table.end()){
                answer.push_back(hash_table[complement]);
                answer.push_back(i);
                return answer;
            }
            hash_table[nums[i]] = i;
        }
        return answer;
    }
};
