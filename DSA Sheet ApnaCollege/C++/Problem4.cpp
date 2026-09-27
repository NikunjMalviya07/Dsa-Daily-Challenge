// LeetCode 50: Pow(x, n)
/* Approach: Binary Exponentiation */  
// Time: O(log n), Space: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long N = n;
        
        if(n < 0) {
            x = 1 / x ;
            N = -N;
        }

        while ( N > 0 ){
            if(N&1){
                ans = ans * x;
            }

            x = x * x;
            N = N >> 1;
        }

        return ans;
    }
};