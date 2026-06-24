class Solution {
public:
    int alocate(vector<int> &v){
        int n = 0;
        for(int i = 0; i < 4; i++){
            if(n == 0 && v[i] != 0) n = v[i];
            else v[i] = 0;
        }
        return n;
    }
    void cut(vector<int> &v, int cr){
        v[cr-1] = 0;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> ans(n+1, {1, 2, 3, 4});
        vector<vector<int>> adj(n+1);
        for(auto path : paths){
            adj[path[0]].push_back(path[1]);
            adj[path[1]].push_back(path[0]);
        }
        vector<int> visited(n+1);
        queue<int> q;
        for(int eve = 1; eve <= n; eve++){
        if(!visited[eve])
        q.push(eve);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            int cr = alocate(ans[cur]);
            for(int ng : adj[cur]) cut(ans[ng], cr);
            visited[cur] = 1;
            for(int ng : adj[cur]) if(!visited[ng]) q.push(ng);
        }
        }
        vector<int> f(n);
        for(int i = 1; i <= n; i++){
            f[i-1] = alocate(ans[i]);
        }
        return f;
    }
};