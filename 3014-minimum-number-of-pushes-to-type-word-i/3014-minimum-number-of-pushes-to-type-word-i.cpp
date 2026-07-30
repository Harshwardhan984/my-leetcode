class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int mul = 1;
        while(n > 0){
            int c = min(8, n);
            ans += mul * c;
            n -= c;
            mul++;
        }
        return ans;
    }
};