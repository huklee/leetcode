class Solution {
public:
    // binary search solution
    //  - average : O(logn)
    //  - worst : O(n) -> every elem is same
    int findMin(vector<int>& v) {
        if (v.size() == 0)
            return 0;
        
        return findMin_(v, 0, v.size() -1);
    }
    
    int findMin_(vector<int>& v, int s, int e){
        while (s < e){
            if (v[s] < v[e])
                e = s;
            else {
                int mid = (s + e)/2;
                if (v[s] > v[mid])
                    e = mid;
                else if (v[s] < v[mid] || v[s] > v[e])
                    s = mid + 1;
                else    // v[s] == v[mid]  && v[s] == v[e]
                    s = s + 1;
            }
        }
        return v[s];

    }
};
