class Solution {
public:
    string smallestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            ans += s[i];
        }
        
        sort(ans.begin(), ans.end());
        if(n % 2 == 1) ans += s[n/2];
        for(int i = n/2-1; i >= 0; i--){
            ans += ans[i];
        }
        return ans;
    }
};