class Solution {
public:
    int ans = 0;
    int solve(vector<vector<int>> &tree, vector<int>& informTime, int head){
        if(tree[head].size() == 0){
            return 0;
        }
        int info = informTime[head];
        int tem = 0;
        for(int i = 0; i < tree[head].size(); i++){
            tem = max(tem, info + solve(tree, informTime, tree[head][i]));
        }
        return tem;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n, vector<int>(0));
        for(int i = 0; i < manager.size(); i++){
            int mng = manager[i];
            if(mng != -1) tree[mng].push_back(i);
        }
        return solve(tree, informTime, headID);
        

    }
};