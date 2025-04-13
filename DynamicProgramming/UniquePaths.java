package DynamicProgramming;

//bottom up
public class UniquePaths {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
}


//top down
class Solution {
    public int uniquePaths(int m, int n) {
        Integer[][] dp = new Integer[m][n];
        return dynamicProgram(m,n,0,0,dp);
    }

    public int dynamicProgram(int m, int n, int i, int j, Integer[][] dp) {
        if(i == m || j == n) return 0;

        if(i==m-1 && j == n-1) return 1;

        if(dp[i][j] != null) return dp[i][j];

        return dp[i][j] = dynamicProgram(m,n,i+1,j,dp) + dynamicProgram(m,n,i,j+1,dp);
    }
}