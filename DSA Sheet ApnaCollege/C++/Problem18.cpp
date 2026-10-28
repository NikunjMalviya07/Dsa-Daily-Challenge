// Leetcode : Longest Substring

class Solution {
public:

int findLongestSub(string s){
    unordered_map<char , int> mp;
    int n = s.length();
    int left = 0;
    int ans = 0;

    for(int right = 0 ; right < n ; right++){
        char c = s[right];
        if(mp.find(c) != mp.end() && mp[c] >= left){
            left = mp[c]+1;
        }

        mp[c] = right;

        ans = max(ans , right - left + 1);
    }

    return ans;
}
    int lengthOfLongestSubstring(string s) {
        return findLongestSub(s);
    }
};