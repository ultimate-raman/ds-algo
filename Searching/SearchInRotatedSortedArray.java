package Searching;

public class SearchInRotatedSortedArray {
    public int search(int[] nums, int target) {
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

            if(nums[left] <= nums[mid]) { ///VVVIIII : issue if equal to not used, case: 3,1   here mid and left both at 3, we consider left sorted
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

        return ans;
    }
}


//More Intuitive to handle left = mid or right = mid case separately
class Solution {
    public int search(int[] nums, int target) {
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

            if (mid == left) {
                if (nums[right] == target) return right;
                return -1;
            }

            if (mid == right) {
                if (nums[left] == target) return left;
                return -1;
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

        return ans;
    }
}