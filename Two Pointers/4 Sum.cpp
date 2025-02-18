class Solution {
public:
    int increase(vector<int>& nums, int current) {
        while(current<nums.size()-1 && nums[current]==nums[current+1]) {
            current++;
        }
        current++;
        return current;
    }

    int decrease(vector<int>& nums, int current) {
        while(current>0 && nums[current]==nums[current-1]) {
            current--;
        }
        current--;
        return current;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4) return ans;

        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-3; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;

            for(int j = i+1; j<nums.size()-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int left = j+1;
                int right = nums.size()-1;

                while(left<right) {
                    long long newTarget = (long long)target-nums[i]-nums[j];

                    if(nums[left]+nums[right]==newTarget) {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});

                        left = increase(nums,left);
                        right = decrease(nums,right);
                    }
                    else if (nums[left]+nums[right]<newTarget) {
                        left = increase(nums,left);
                    }
                    else {
                        right = decrease(nums,right);
                    }
                }

            }
        }

        return ans;
    }
};