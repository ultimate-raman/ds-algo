class Solution {
    public:
        bool canJump(vector<int>& nums) {
            if(nums.size()==1) return true;
            int i = 0;
            int power = nums[0];
    
            while(i<nums.size() && power>0) {
                power = max(power-1,nums[i]);
                if(power >= nums.size()-1-i) {
                    return true;
                }
                i++;
            }
    
            return false;
        }
    };