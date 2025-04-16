package Searching;

public class SearchInRotatedSortedArray2 {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int ans = -1;
        int mid = 0;

        while(left<=right) {
            mid = (left + right)/2;

            if(nums[mid] == target) {
                ans = mid;
                break;
            }

            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid]) {
                if(target >= nums[left] && target <=nums[mid]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            } else {
                if(target >= nums[mid] && target <=nums[right]) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
        }

        return ans == -1 ? false : true;
    }
}




class Solution {
    public boolean search(int[] nums, int target) {
        int left = 0;
        int right = nums.length-1;
        int ans = -1;
        int mid = 0;

        while(left<=right) {
            mid = (left + right)/2;

            if(nums[mid] == target) {
                ans = mid;
                break;
            }

            if(nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue;
            }


            if (nums[mid] == nums[left]) {
                left = mid+1;
                continue;
            }

            if (nums[mid] == nums[right]) {
                right =  mid - 1;
                continue;
            }

            if(nums[left] < nums[mid]) {
                if(target >= nums[left] && target <=nums[mid]) {
                    right = mid-1;
                }
                else {
                    left = mid+1;
                }
            } else {
                if(target >= nums[mid] && target <=nums[right]) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
        }

        return ans == -1 ? false : true;
    }
}