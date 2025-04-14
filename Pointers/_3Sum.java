package Pointers;
import java.util.*;

public class _3Sum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();

        Arrays.sort(nums);

        int base = 0;

        while(base < nums.length-2) {
            int left = base + 1;
            int right = nums.length-1;
            int required = -nums[base];

            while(left < right) {
                if(nums[left] + nums[right] == required) {
                    ans.add(Arrays.asList(nums[base],nums[left],nums[right]));
                    left = increment(left, nums);
                    right = decrement(right, nums);
                } else if(nums[left] + nums[right] > required) {
                    right = decrement(right, nums);
                } else {
                    left = increment(left, nums);
                }
            }

            base = increment(base, nums);
        }

        return ans;
    }

    public int increment(int i, int[] nums) {
        while (i + 1 < nums.length && nums[i] == nums[i + 1]) i++;
        return i + 1;
    }

    public int decrement(int i, int[] nums) {
        while (i - 1 > 0 && nums[i] == nums[i - 1]) i--;
        return i - 1;
    }
}
