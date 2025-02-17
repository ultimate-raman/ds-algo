class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int ans = 0;
            int minSoFar = INT_MAX;
    
            for(int price: prices) {
                ans = max(ans,price-minSoFar);
                minSoFar = min(minSoFar, price);
            }
    
            return ans;
        }
    };