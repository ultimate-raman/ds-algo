package Sorting;

public class MergeSort {
    private void mergeSort(int[] nums, int start, int end) {
        if(start>=end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }

    private void merge(int[] nums, int start, int mid, int end) {
        int[] temp = new int[end-start+1];

        int left = start;
        int right = mid+1;

        int k = 0;

        while(left<=mid && right <=end) {
            if (nums[left] <= nums[right]) {
                temp[k++] = nums[left++];
            } else {
                temp[k++] = nums[right++];
            }
        }

        while(left<=mid){
            temp[k++] = nums[left++];
        }

        while(right<=end) {
            temp[k++] = nums[right++];
        }

        for (int t = 0; t < k; ++t) {
            nums[start + t] = temp[t];
        }
    }

    public int[] sortArray(int[] nums) {
        mergeSort(nums,0,nums.length-1);
        return nums;
    }
}
