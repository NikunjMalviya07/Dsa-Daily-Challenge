// LeetCode 169: Majority Element
/* Approach: Using Bayer-Moore-Voting Algo Using Candidate and Count */  
// Time: O(n), Space: O(1)

class Solution {
    public int majorityElement(int[] nums) {
        int n = 0;
        int m = 0;

        for( int x : nums) {
            if( m == 0 ){
                n = x;
            }

            if( x == n) {
                m++;
            } else {
                m--;
            }
        }

        return n;
    }
}