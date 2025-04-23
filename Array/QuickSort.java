package Array;

public class QuickSort {
    public int[] sortArray(int[] nums) {
        sorter(nums,0,nums.length-1);
        return nums;
    }

    public void sorter(int[] nums, int low, int high) {
        if(low >= high) return;
        int pivot = pivotFinder(nums,low,high);
        sorter(nums,low,pivot-1);
        sorter(nums,pivot+1,high);
    }

    public int pivotFinder(int[] nums, int low, int high) {
        int pivot = low;

        int i = low;
        int j = high;

        while(i < j) {
            while(i<=high && nums[i] <= nums[pivot]) i++;
            while(j>=low && nums[j] > nums[pivot]) j--; //if equality used for nums[j] >= nums[pivot], then uncomment line 33 because j may become lower than pivot

            if(i<j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        // if(j<pivot) return pivot;

        int temp = nums[pivot];
        nums[pivot] = nums[j];
        nums[j] = temp;

        return j;
    }
}
