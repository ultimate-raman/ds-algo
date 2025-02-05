//Merge Sort
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


//Merge Sort a bit optimized
class Solution {
private:
    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> temp(end - start + 1);

        int i = start;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        while (j <= end) {
            temp[k++] = nums[j++];
        }

        
        for (int t = 0; t < k; ++t) {
            nums[start + t] = temp[t];
        }
    }

    
    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
