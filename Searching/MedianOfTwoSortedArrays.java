package Searching;

public class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        if (nums1.length > nums2.length) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.length;
        int n2 = nums2.length;

        int left = 0;
        int right = n1;

        //binary search will decide how many elements can be picked from nums1, min 0, max n1
        while(left<=right) {
            int i = (left + right) / 2;
            int j = (n1 + n2 + 1) / 2 - i;

            int l1 = (i == 0 ? Integer.MIN_VALUE : nums1[i - 1]);
            int r1 = (i == n1 ? Integer.MAX_VALUE : nums1[i]);
            int l2 = (j == 0 ? Integer.MIN_VALUE : nums2[j - 1]);
            int r2 = (j == n2 ? Integer.MAX_VALUE : nums2[j]);


            if(l1 <= r2 && l2 <= r1) {
                if((n1+n2) %2 ==0) {
                    return (Math.max(l1,l2) + Math.min(r1,r2))/2.0;
                }
                else return Math.max(l1,l2);
            }

            else if(l1>r2) {
                right = i - 1;
            }
             
            else {
                left = i + 1;
            }
        }

        return -1;
    }
}