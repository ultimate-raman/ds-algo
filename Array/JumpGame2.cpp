class Solution {
    public:
        int jump(vector<int>& nums) {
            if(nums.size()==0 || nums.size()==1) return 0;
            int i = 0;
            int ans=1;
            int reach = nums[0];
    
            while(i<nums.size()) {
                if(reach>=nums.size()-1) {
                    return ans;
                }
    
                ans++;
    
                int temp = reach;
                reach = nums[i];
                while(i<=temp) {
                    reach = max(i+nums[i],reach);
                    i++;
                }
            }
    
            return ans;
        }
    };