package DynamicProgramming;

public class LongestCommonSubsequence {

    //bottom up
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }


    //top down
    class Solution {
        public int longestCommonSubsequence(String text1, String text2) {
            Integer[][] dp = new Integer[text1.length()][text2.length()];
            return dynamic(text1,text2,0,0,dp);
        }
    
        public int dynamic(String text1, String text2, int i, int j, Integer[][] dp) {
            if(i == text1.length() || j == text2.length()) return 0;
    
            if(dp[i][j] != null) return dp[i][j];
    
            if(text1.charAt(i) == text2.charAt(j)) {
                return dp[i][j] = 1 + dynamic(text1, text2, i+1, j+1, dp);
            }
            else {
                return dp[i][j] = Math.max(dynamic(text1, text2, i, j+1, dp), dynamic(text1, text2, i+1, j, dp));
            }
        }
    }

}
