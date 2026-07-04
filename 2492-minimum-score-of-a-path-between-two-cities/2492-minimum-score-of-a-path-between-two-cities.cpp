class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto ng : roads){
            adj[ng[0]].push_back({ng[1], ng[2]});
            adj[ng[1]].push_back({ng[0], ng[2]});
        }
        vector<int> visited(n+1);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto pr : adj[v]){
                int city = pr.first, dis = pr.second;
                ans = min(ans, dis);
                if(!visited[city]){
                    q.push(city);
                    visited[city] = 1;
                }
            }
        }
        return ans;
    }
};