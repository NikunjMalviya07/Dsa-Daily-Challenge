// LeetCode 2965: Find Missing and Repeated Values
// Approach: frequency map on flattened grid, track sum for missing, count==2 for repeated
// Time: O(n^2), Space: O(n^2)

class Solution {

    public int[] missingAndRepeated(int[][] grid) {
        int[] ans = new int[2];
        int n = grid.length;
        int sum = (n * n * (n * n + 1)) / 2;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int count = mp.getOrDefault(val, 0) + 1;
                mp.put(val, count);

                if (count == 1) {
                    sum -= val;
                }
                if (count == 2) {
                    ans[0] = val;
                }
            }
        }

        ans[1] = sum;
        return ans;
    }

    public int[] findMissingAndRepeatedValues(int[][] grid) {
        return missingAndRepeated(grid);
    }
}