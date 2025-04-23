package Array;

public class MergeSort {
    public void merge(int[] nums, int left, int mid, int right) {
        int[] temp = new int[right-left+1];
        int k = 0;

        int i = left;
        int j = mid+1; 
        while(i <= mid && j <= right){
            if(nums[i]<= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                temp[k++] = nums[j++];
            }
        }

        while(i<=mid){
            temp[k++] = nums[i++];
        }

        while(j<=right){
            temp[k++] = nums[j++];
        }

        k = 0;
        for(int it=left;it<=right;it++) {
            nums[it] = temp[k++];
        }
    }

    public void merger(int[] nums, int left, int right){
        if(left>=right) return;

        int mid = (left+right)/2;

        merger(nums,left,mid);
        merger(nums,mid+1,right);
        merge(nums,left,mid,right);
    }

    public int[] mergeSort(int[] nums) {
        merger(nums,0,nums.length-1);

        return nums;
    }
}