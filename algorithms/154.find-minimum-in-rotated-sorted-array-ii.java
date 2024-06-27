// Leetcode 154. minimum rotation - O(log(N)) solution using binary search
public class Solution {
    public int findMin(int[] v) {
        if (v.length == 0) {
            return 0;
        }
        
        return findMin_(v, 0, v.length - 1);
    }
    
    private int findMin_(int[] v, int s, int e) {
        while (s < e) {
            if (v[s] < v[e]) {
                e = s;
            } else {
                int mid = (s + e) / 2;
                if (v[s] > v[mid]) {
                    e = mid;
                } else if (v[s] < v[mid] || v[s] > v[e]) {
                    s = mid + 1;
                } else { // v[s] == v[mid] && v[s] == v[e]
                    s = s + 1;
                }
            }
        }
        return v[s];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] v = {3, 4, 5, 1, 2};
        System.out.println(solution.findMin(v)); // Output: 1

        int[] v2 = {4, 5, 6, 7, 0, 1, 2};
        System.out.println(solution.findMin(v2)); // Output: 0

        int[] v3 = {1, 1, 1, 1, 1, 0, 1, 1};
        System.out.println(solution.findMin(v3)); // Output: 0

        int[] v4 = {2, 2, 2, 0, 1, 2};
        System.out.println(solution.findMin(v4)); // Output: 0
    }
}
