class Solution {
public:
    // Dynamic Programming : T(n) = O(m*n) solution
    // Minimal space solution : O(min(m, n))
    int uniquePaths_DP2(int m, int n) {
        int arr[100] = {0,};
        int min_axis = min(m, n);
        int max_axis = max(m, n);
        
        for (int i=0; i < min_axis; i++)
            arr[i] = 1;
            
        for (int j=0; j < max_axis - 1; j++)
            for (int i=0; i < min_axis; i++)
                arr[i] = (i == 0 )? arr[i] : arr[i - 1] + arr[i];
        
        return arr[min_axis - 1];
    }

    // Dynamic Programming : T(n) = O(m*n) solution
    // Normal 2D Solution : O(m*N)
    int uniquePaths_DP1(int m, int n) {
        int DP[100][100] = {0,};
        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                if (i == 0 && j == 0){
                    DP[i][j] = 1;
                    continue;
                }
                
                int down = (i - 1 < 0) ? 0 : DP[i - 1][j];
                int right = (j - 1 < 0) ? 0 : DP[i][j - 1];
                DP[i][j] = down + right;
            }
        }
        return DP[m-1][n-1];
    }

    int uniquePaths(int m, int n){
		return uniquePaths_DP2(m,n);
	}
};
