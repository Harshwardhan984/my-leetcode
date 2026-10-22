class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans;
        for(auto v : matrix){
            int t = 0;
            for(int i : v) t += i;
            ans.push_back(t);
        }
        return ans;
    }
};