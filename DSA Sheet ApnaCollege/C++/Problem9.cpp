class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1 ; j < n ; ){
                int left = j + 1;
                int right = n - 1;

                while (left < right){
                    long long currSum = (long long)nums[i] + (long long)nums[j] 
                    + (long long)nums[left] + (long long)nums[right];

                    if(currSum == target){
                        ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left-1]) left++; 
                        while(left < right && nums[right] == nums[right+1]) right--;
                        
                    }

                    else if (currSum < target){
                            left++;
                    }

                    else {
                            right--;
                    }
                }

                j++;
                while(j < n && nums[j] == nums[j-1]) j++;
            }
        }

        return ans;
    }
};