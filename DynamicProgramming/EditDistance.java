package DynamicProgramming;

public class EditDistance {

    //top down
    public int minDistance(String word1, String word2) {
        Integer[][] dp = new Integer[word1.length()][word2.length()];
        return dynamic(word1,word2,0,0, dp);
    }

    private int dynamic(String word1, String word2, int i, int j, Integer[][] dp) {
        if(i==word1.length()) return word2.length()-j;
        if(j==word2.length()) return word1.length()-i;

        if(dp[i][j]!=null) return dp[i][j];

        if(word1.charAt(i) == word2.charAt(j)) return dynamic(word1,word2,i+1,j+1, dp);

        int add = 1 + dynamic(word1,word2,i,j+1,dp);
        int replace = 1 + dynamic(word1,word2,i+1,j+1,dp);
        int delete = 1 + dynamic(word1,word2,i+1,j,dp);

        return dp[i][j] = Math.min(add, Math.min(replace, delete));
    }





    //bottom up
    class Solution {
        public int minDistance(String word1, String word2) {
            int m = word1.length(), n = word2.length();
            int[][] dp = new int[m + 1][n + 1];
    
            for (int i = 0; i <= m; i++) {
                dp[i][n] = m - i;
            }
            for (int j = 0; j <= n; j++) {
                dp[m][j] = n - j;
            }
    
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (word1.charAt(i) == word2.charAt(j)) {
                        dp[i][j] = dp[i + 1][j + 1];
                    } else {
                        int insert = 1 + dp[i][j + 1];
                        int replace = 1 + dp[i + 1][j + 1];
                        int delete = 1 + dp[i + 1][j];
                        dp[i][j] = Math.min(insert, Math.min(replace, delete));
                    }
                }
            }
    
            return dp[0][0];
        }
    }
    
}
