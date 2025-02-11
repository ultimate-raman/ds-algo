class Solution {
    public:
        int climbStairs(int n) {
            vector<int> ans(n+1,-1);
    
            if(n <= 3) return n;
    
            ans[0] = 0;
            ans[1] = 1;
            ans[2] = 2;
            ans[3] = 3;
    
            for(int i=4; i<=n; i++) {
                ans[i] = ans[i-1] + ans[i-2];
            }
    
            return ans[n];
        }
    };


class Solution {
    public:
    
        int helper(int n, vector<int> &dp) {
            if(n <= 3) {
                return n;
            }
            if(dp[n] != -1) return dp[n];
    
            return dp[n] = helper(n-1, dp) + helper(n-2, dp);
        }
    
        int climbStairs(int n) {
            if(n <= 3) {
                return n;
            }
    
            vector<int> dp(n+1,-1);
    
            return helper(n,dp);
        }
    };