class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();

        unordered_map<long long, int> edgs;
        for(int i = 0; i < n; i++){
            long long now = 0;
            for(int j = 0; j < wall[i].size()-1; j++){
                int len = wall[i][j];
                now += len;
                edgs[now]++;
            }
        }
        int ans = n;
        for(auto p : edgs){
            int brk = n - p.second;
            ans = min(ans, brk);
        }
        return ans;
    }
};