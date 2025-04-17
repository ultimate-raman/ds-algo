package Searching;

import java.util.Arrays;

public class AggressiveCows {
    public int aggressiveCows(int[] nums, int k) {
        Arrays.sort(nums);
        
        int left = 1;
        int right = 0;

        for(int num: nums) {
            right = Math.max(right,num);
        }

        int mid = 0;

        int ans = 0;

        while(left <= right) {
            mid = (left + right)/2;

            if(canPlaceWithDistance(nums,k,mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
        
    }

    private boolean canPlaceWithDistance(int[] nums, int k, int distance) {
        int count = 1;
        int j = 1;
        int distanceFromLast = 0;
        while(j<nums.length) {
            distanceFromLast += nums[j] - nums[j-1]; 
            if(distanceFromLast >= distance) {
                count++;
                distanceFromLast = 0;
            }
            j++;
        }

        return count >= k;
    }
}
