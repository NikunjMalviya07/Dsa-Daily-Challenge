// Leetcode Problem 74 : Search a 2D Matrix
// Approach : Binary Search With complete Logic
// Time Complexity : O(log(m*n)) where m is the number of rows and n is the number of columns
// Space Complexity : O(1) as we are not using any extra space

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); // row number
        int n = matrix[0].size(); // column number

        int lc = 0;
        int rc = n-1;
        int top = 0;
        int bottom = m - 1;

            while(top <= bottom){
                int rm = (top + bottom) / 2;
                int cm = (lc + rc) / 2;

                if(target == matrix[rm][cm]){
                    return true;
                }

                else if (target < matrix[rm][cm]){
                    bottom = rm;
                        int left = 0;
                        int right = cm-1;

                            while(left <= right) {
                                int mid = (left + right)/2;

                                    if(matrix[bottom][mid] == target) {
                                        return true;
                                    } else if (matrix[bottom][mid] > target) {
                                        right = mid-1;
                                    } else {
                                        left = mid+1;
                                    }
                                }     
                        
                        bottom = rm-1;
                    }

                    else if (target > matrix[rm][cm]) {
                        top = rm;
                        int left = cm +1;
                        int right = n-1;

                            while(left <= right) {
                                int mid = (left + right)/2;

                                    if(matrix[top][mid] == target) {
                                        return true;
                                    } else if (matrix[top][mid] > target) {
                                        right = mid-1;
                                    } else {
                                        left = mid+1;
                                    }
                                }     
                        
                        top = rm+1;
                    }
        
            }

        return false;
    }
};

// Approach 2 : Binary Search By treating the 2D matrix as a 1D array

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / n; // Calculate the row index important way
            int col = mid % n; // Calculate the column index important way

            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};