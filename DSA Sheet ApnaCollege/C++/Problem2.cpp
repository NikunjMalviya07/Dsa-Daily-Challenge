// LeetCode 88: Merge Sorted Array
/* Approach: Merging Two Sorted array. Note : In this question we compare the elemnts from last and itrate using 3 variables */  
// Time: O(m+n), Space: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1 ;
        int j = n - 1 ;
        int idx = m + n - 1 ;

        while (i >= 0 && j >= 0) {
            if(nums1[i] < nums2[j]){
                nums1[idx--] = nums2[j--];
            } else {
                nums1[idx--] = nums1[i--];
            }
        }

        while( j >= 0 ){
            nums1[idx--] = nums2[j--];
        }
    }
};