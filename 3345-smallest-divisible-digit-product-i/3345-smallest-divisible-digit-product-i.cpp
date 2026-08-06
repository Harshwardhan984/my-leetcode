class Solution {
public:
    int prod(int n){
        string s = to_string(n);
        int ans = 1;
        for(char c:s){
            ans *= (c-'0');
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(prod(n++)%t == 0) return n-1;
        }
        return 0;
    }
};