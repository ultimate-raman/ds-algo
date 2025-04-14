class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            int i = 0;
            while(i<=nums.size()-3) {
                int left = i+1;
                int right = nums.size()-1;
                while(left < right) {
                    if(nums[left] + nums[right] == -1 * nums[i]) {
                        ans.push_back({nums[i],nums[left],nums[right]});
                        while(left<nums.size()-1 && nums[left]==nums[left+1]) {
                            left++;
                        }
                        left++;
                        while(right > 0 && nums[right]==nums[right-1]) {
                            right--;
                        }
                        right--;
                    }
                    else if (nums[left] + nums[right] < -1 * nums[i]) {
                        left++;
                    }
    
                    else {
                        right--;
                    }
                }
    
                while(i<nums.size()-1 && nums[i]==nums[i+1]) {
                    i++;
                }
                i++;
            }  
    
            return ans; 
        }
    };