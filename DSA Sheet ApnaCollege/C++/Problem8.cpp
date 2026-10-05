// Leetcode : 15 : 3Sum
// Approach : Brute Force
// Time Complexity : O(n^3) Time Limit Excceeded

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;

        for(int i = 0 ; i < n ; i++){
            for (int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){

                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> trip = {nums[i] , nums[j] , nums[k]};
                        sort(trip.begin() , trip.end());

                        if(s.find(trip) == s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// Approach : Hashing
// Time Complexity : O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> uqTriplet;

        for(int i = 0 ; i < n ; i++){
            int target = -nums[i];
            set<int> s;

            for(int j = i + 1 ; j < n ; j++){
                int third = target - nums[j];
                if(s.find(third) != s.end()){
                    vector<int> trip = {nums[i] , nums[j] , third};
                    sort(trip.begin() , trip.end());
                    uqTriplet.insert(trip);
                }
                s.insert(nums[j]);
            } 
        }

        ans.assign(uqTriplet.begin() , uqTriplet.end());

        return ans;
    }
};