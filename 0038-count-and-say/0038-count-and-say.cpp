class Solution {
public:
    string makerle(string s){
        string ans = "";
        int cnt = 1;
        char cur = s[0];
        for(int i = 1; i < s.size(); i++){
            if(cur == s[i]) cnt++;
            else{
                ans += to_string(cnt);
                ans += cur;
                cur = s[i];
                cnt = 1;
            }
        }
        ans += to_string(cnt);
                ans += cur;
                return ans;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        else return makerle(countAndSay(n-1));
    }
};