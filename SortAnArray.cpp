class Solution {
public:
    vector<int> mergeSortedArrays (vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }

        vector<int> ans;

        int mid = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        vector<int> leftSortedArray = sortArray(left);
        vector<int> rightSortedArray = sortArray(right);

        return mergeSortedArrays(leftSortedArray,rightSortedArray);
    }
};