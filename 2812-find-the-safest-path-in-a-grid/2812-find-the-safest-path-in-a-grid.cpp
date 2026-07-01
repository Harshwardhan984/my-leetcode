class Solution {
public:
    bool canReach(vector<vector<int>>& dist, int v) {
    int n = dist.size();
    if (dist[0][0] < v) return false;  // start not safe enough

    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;

    vector<int> dx = {1,-1,0,0}, dy = {0,0,1,-1};

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (x == n-1 && y == n-1) return true;  // reached destination

        for (int k=0; k<4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx>=0 && ny>=0 && nx<n && ny<n && !visited[nx][ny] && dist[nx][ny] >= v) {
                visited[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    return false;
}

    int maximumSafenessFactor(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int,int>> q;

   
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    vector<int> dx = {1,-1,0,0}, dy = {0,0,1,-1};
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k], ny = y+dy[k];
            if (nx>=0 && ny>=0 && nx<n && ny<n && dist[nx][ny] > dist[x][y]+1) {
                dist[nx][ny] = dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    int lo=0, hi=n*2, ans=0;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (canReach(dist, mid)) { ans=mid; lo=mid+1; }
        else hi=mid-1;
    }
    return ans;
}

};