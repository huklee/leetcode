class Solution {
public:
    // Two pointer solutions : O(N)
    vector<int> twoSum(vector<int>& numbers, int target) {
        int S = 0, E = numbers.size() - 1;
        while (S < E){
            while (target - numbers[S] < numbers[E])
                E--;
            if (target - numbers[S] == numbers[E])
                return vector<int>{S + 1, E + 1};
            else
                S++;
        }
        return vector<int>{-1,-1};
    }
};
