// LeetCode 169: Majority Element
/* Approach: Sorting the array and then returning the middle element */  
// Time: O(nlogn), Space: O(n)

class Solution {
public:

void merge (vector<int>& nums , int si , int ei, int mid){
    vector<int> temp;
    int i = si;
    int j = mid + 1;
    int x = 0;
    while(i<= mid && j <= ei){
        if(nums[i]<=nums[j]){
            temp.push_back(nums[i++]);
        }
        else {
            temp.push_back(nums[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(nums[i++]);   
    }
    while(j<=ei){
        temp.push_back(nums[j++]);   
    }

    for(int i = si ; i<= ei; i++){
        nums[i] = temp[x++];
    }
}

void mergSort (vector<int>& nums , int si , int ei){
    // base case 
    if (si >= ei) return;
    int mid = si + (ei - si)/2;
    mergSort ( nums ,  si ,  mid); // lefthalf
    mergSort ( nums ,  mid +1 ,  ei); // right half
    merge ( nums ,  si ,  ei,  mid); // merge
}

int majorityElement(vector<int>& nums) {
    int si = 0;
    int ei = nums.size() - 1;
    mergSort(nums , si ,ei);
        int n = (nums.size()/2);
        return nums[n];
    }
};