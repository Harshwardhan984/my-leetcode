class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> str;
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++) str.push_back(grid[j][i]);
        }
        int nn = str.size(), l = 0;
        k = k % nn;
        vector<int> str2;
        for(int i = 0; i < k; i++){
            str2.push_back(str[nn-i-1]);
        }
        reverse(str2.begin(), str2.end());
        for(int i = 0; i <= nn-1-k; i++) str2.push_back(str[i]);
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                grid[j][i] = str2[l];
                l++;
            }
        }
        return grid;
    }
};