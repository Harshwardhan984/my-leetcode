class Solution {
public:
    int check(vector<vector<int>>& grid, int k, int i, int j){
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || i == n) return 0;
        if(j < 0 || j == m) return 0;
        if(grid[i][j] == 0) return 0;

        int add = grid[i][j] % k;

        grid[i][j] = 0;
        
        add += check(grid, k, i+1, j) % k;
        add += check(grid, k, i-1, j) % k;
        add += check(grid, k, i, j+1) % k;
        add += check(grid, k, i, j-1) % k;

        
        return add;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0 && check(grid, k, i, j) % k == 0) ans++;
            }
        }
        return ans;
    }
};