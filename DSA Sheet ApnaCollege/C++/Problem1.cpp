// LeetCode 2965: Find Missing and Repeated Values
// Approach: frequency map on flattened grid, track sum for missing, count==2 for repeated
// Time: O(n^2), Space: O(n^2)

class Solution {
public:

vector<int> missingAndRepeated(vector<vector<int>>& grid){
    vector<int> ans(2);
    int n = grid.size();
    int sum = (n*n*(n*n + 1 ))/2;
    unordered_map<int, int> mp;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++) {
            mp[grid[i][j]]++;
            if( mp[grid[i][j]] == 1){
                sum -= grid[i][j];
            }
            if(mp[grid[i][j]] == 2 ){
                ans[0] = grid[i][j] ;
            }
        }
    }

    ans[1] = sum;

    return ans;
}

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        return missingAndRepeated(grid);

    }
};