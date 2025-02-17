class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 1) return 1;
    
            int count = 1;
    
            int j = 1;
    
            for(int  i=1; i<nums.size();i++) {
                if(nums[i] == nums[j-1]) {
                    count++;
    
                    if(count<=2) {
                        nums[j] = nums[i];
                        j++;
                    }
                }
                
                else if (nums[i] != nums[j-1]) {
                    nums[j] = nums[i];
                    j++;
                    count=1;
                }
    
            }
    
            return j;
        }
    };



    //optimized
    class Solution {
        public:
            int removeDuplicates(vector<int>& nums) {
                if (nums.size() <= 2) return nums.size();
        
                int j = 2;
        
                for (int i = 2; i < nums.size(); i++) {
                    if (nums[i] != nums[j - 2]) {
                        nums[j] = nums[i];
                        j++;
                    }
                }
        
                return j;
            }
        };
        