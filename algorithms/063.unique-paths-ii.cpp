class Solution {
public:
    // Dynamic Programming of O(mn) time complexity
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        assert(obstacleGrid.size() > 0 && obstacleGrid[0].size() > 0);
        vector<vector<int>>& mat = obstacleGrid;
        int m = mat.size();
        int n = mat[0].size();
        int DP[101][101] = {0,};
        DP[0][1] = 1;   // for staring point
        for (int i=1; i <= m; i++){
            for (int j=1; j <= n; j++){
                if (mat[i-1][j-1] == 1)
                    DP[i][j] = 0;
                else
                    DP[i][j] = DP[i - 1][j] + DP[i][j -1];
            }
        }
        return DP[m][n];
    }
};
