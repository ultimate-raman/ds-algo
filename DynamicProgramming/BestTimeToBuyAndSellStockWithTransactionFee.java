package DynamicProgramming;

public class BestTimeToBuyAndSellStockWithTransactionFee {

    //top down
    public int maxProfit(int[] prices, int fee) {
        Integer[][] dp = new Integer[prices.length][2];
        return dynamic(prices,fee,0,1,dp);
    }

    private int dynamic(int[] prices, int fee, int index, int toBuy, Integer[][] dp) {
        if(index == prices.length) return 0;

        if(dp[index][toBuy]!=null) return dp[index][toBuy];

        if(toBuy == 1) {
            return dp[index][toBuy] = Math.max(dynamic(prices,fee,index+1,0,dp) - prices[index] -fee, dynamic(prices,fee,index+1,1,dp));
        }
        else {
            return dp[index][toBuy] = Math.max(dynamic(prices,fee,index+1,1,dp) + prices[index] , dynamic(prices,fee,index+1,0,dp));
        }
    }


    //bottom up
    class Solution {
        public int maxProfit(int[] prices, int fee) {
            int n = prices.length;
            int[][] dp = new int[n + 1][2];
    
            for (int index = n - 1; index >= 0; index--) {
                dp[index][1] = Math.max(
                    -prices[index] - fee + dp[index + 1][0],
                    dp[index + 1][1]
                );
    
                dp[index][0] = Math.max(
                    prices[index] + dp[index + 1][1],
                    dp[index + 1][0]
                );
            }
    
            return dp[0][1];
        }
    }
    
}
