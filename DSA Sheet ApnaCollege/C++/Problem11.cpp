// Leetcode : 73 : Set Matrix Zeroes
// Approach : Logic by using hashing and then setting the values to zero
// Time Complexity : O(m*n) where m is the number of rows and n is the number of columns
// Space Complexity : O(m+n) as we are using extra space for hashing

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map< int , vector<pair<int,int>>> mp;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    mp[matrix[i][j]].push_back({i , j});
                }
            }
        }


        for(auto entry : mp){
                for(auto position : entry.second){
                    for(int i = 0 ; i < m ; i++){
                        if(matrix[i][position.second] == 0){
                            continue;
                        } else {
                            matrix[i][position.second] = 0;
                        }
                    }

                    for(int i = 0 ; i < n ; i++){
                        if(matrix[position.first][i] == 0){
                            continue;
                        } else {
                            matrix[position.first][i] = 0;
                        }
                    }
                }
        }
    }
};