class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grd(m);
        for(int i = 0; i < m; i++){
            string tem = "";
            for(int j = 0; j < n; j++){
                tem += '#';
            }
            grd[i] = tem;
        }
        int i = 0, j = 0;
        while(i != m-1 || j != n-1){
            grd[i][j] = '.';
            int r = rand() % 2;
            if(r){
                if(i+1 < m) i++;
                else if(j+1 < n)j++;
            }
            else{
                if(j+1 < n)j++;
                else if(i+1 < m) i++;
            }
        }
        grd[i][j] = '.';
        return grd;
    }
};