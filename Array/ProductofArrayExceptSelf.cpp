class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> ans(nums.size());
    
            int product  = nums[0];
            ans[0] = 1;
            for(int i=1; i<ans.size();i++) {
                ans[i] = product;
                product = product * nums[i];
            }
    
            product = nums[nums.size()-1];
            for(int i=nums.size()-2; i>=0;i--) {
                ans[i] = ans[i]*product;
                product = product*nums[i];
            }
    
            return ans;
        }
    };