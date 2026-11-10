// Subarray Sum Equals K
// Really good question must visited

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        
        int crr_sum = 0;
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            crr_sum += nums[i];
            int old_sum = crr_sum - k;
            
            if (mp.find(old_sum) != mp.end()) {
                ans += mp[old_sum];
            }
            
            mp[crr_sum]++;
        }
        
        return ans;
    }
};