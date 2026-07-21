class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int>> st;
        char cur = s[0];
        int r = 0;
        st.push_back({cur, 1});
        for(int i = 1; i < s.size(); i++){
            if(s[i] == cur){
                 int now = st[r].second;
                 st[r] = {cur, now+1};
            }
            else{
                st.push_back({s[i], 1});
                r++;
                cur = s[i];
            }
        }
        int one = 0;
        for(char c : s) if(c == '1') one++;
        int delta = 0;
        for(int i = 1; i < st.size()-1; i++){
            if(st[i].first == '1' && st[i-1].first == '0' && st[i+1].first == '0') delta = max(delta, st[i-1].second + st[i+1].second);
        }
        return one + delta;
    }
};