class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int count = 0;
            int majorityElement = 0;
    
            for (int num : nums) {
                if (count == 0) {
                    majorityElement = num;
                }
                count += (num == majorityElement) ? 1 : -1;
            }
    
            return majorityElement;
        }
    };
    